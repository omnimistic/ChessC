#include "Board.h"
#include "Color.h"
#include "../pieces/Pawn.h"
#include <iostream>

Board::Board() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            grid[row][col] = nullptr;
            highlighted[row][col] = false;
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

Piece* Board::getPiece(int r, int c) {
    if (r < 0 || r > 7 || c < 0 || c > 7) return nullptr;
    return grid[r][c];
}

void Board::movePiece(int startR, int startC, int endR, int endC) {
    grid[endR][endC] = grid[startR][startC]; 
    grid[startR][startC] = nullptr;          
}

void Board::highlightMoves(std::vector<std::pair<int, int>> moves) {
    for (auto move : moves) {
        highlighted[move.first][move.second] = true;
    }
}

void Board::clearHighlights() {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            highlighted[r][c] = false;
        }
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

            if (highlighted[row][col]) {
                std::cout << Color::Magenta << textColor << squareContent << Color::Reset;
            } else if (isLightSquare) {
                std::cout << lightSquareColor << textColor << squareContent << Color::Reset;
            } else {
                std::cout << darkSquareColor << textColor << squareContent << Color::Reset;
            }
        }
        std::cout << "\n"; 
    }
    std::cout << "   a b c d e f g h \n";
}