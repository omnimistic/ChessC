#include <iostream>
#include "Board.h"
#include "Color.h"
#include "Pawn.h"

Board::Board() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            grid[row][col] = nullptr;
        }
    }
}

Board::~Board() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (grid[row][col] != nullptr) {
                delete grid[row][col];
            }
        }
    }
}

void Board::setupStartingPosition() {
    for (int col = 0; col < 8; col++) {
        grid[6][col] = new Pawn(true);
        grid[1][col] = new Pawn(false);
    }
}

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
            std::string textColor = "";

            if (grid[row][col] != nullptr) {
                
                squareContent = " " + grid[row][col]->symbol; 
                
                if (grid[row][col]->isWhite) {
                    textColor = Color::Bold + Color::WhiteText;
                } else {
                    textColor = Color::Bold + Color::BlackText;
                }
            }

            if (isLightSquare) {
                std::cout << lightSquareColor << textColor << squareContent << Color::Reset;
            } else {
                std::cout << darkSquareColor << textColor << squareContent << Color::Reset;
            }
        }
        std::cout << "\n"; 
    }
    std::cout << "   a b c d e f g h \n";
}