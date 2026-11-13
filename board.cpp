#include <iostream>
#include <string>
#include "Board.h"
#include "Color.h"


void Board::printBoard() {
    std::string lightSquareColor;
    std::string darkSquareColor;

    switch (currentTheme) {
        case Theme::Classic: 
            lightSquareColor = Color::White;
            darkSquareColor = Color::Green; 
            break;
        case Theme::Wood: 
            lightSquareColor = Color::Yellow; 
            darkSquareColor = Color::Red; 
            break;
        case Theme::Dark: 
            lightSquareColor = Color::DarkGray; 
            darkSquareColor = Color::Black; 
            break;
        case Theme::Ocean: 
            lightSquareColor = Color::Cyan; 
            darkSquareColor = Color::Blue; 
            break;
    }

    for (int row = 0; row < 8; row++) {
        std::cout << 8 - row << " "; 

        for (int col = 0; col < 8; col++) {
            bool isLightSquare = ((row + col) % 2 == 0);
            std::string squareContent = "  "; 

            if (isLightSquare) {
                std::cout << lightSquareColor << squareContent << Color::Reset;
            } else {
                std::cout << darkSquareColor << squareContent << Color::Reset;
            }
        }
        std::cout << "\n"; 
    }
    std::cout << "   a b c d e f g h \n";
}