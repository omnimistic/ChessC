#include <iostream>
#include <string>
#include "core/Board.h"
#include "core/Theme.h"

std::pair<int, int> parseInput(std::string input) {
    int col = input[0] - 'a';
    int row = 8 - (input[1] - '0');
    return {row, col};
}

int main() {
    std::cout << "Hi LOL! \n\n";
    
    Board board;
    board.currentTheme = Theme::Wood; 
    
    board.setupStartingPosition();
    
    while (true) {

        board.printBoard();
        std::string startStr, endStr;
        std::cout << "\nYour move. Select a piece (example: e2): ";
        std::cin >> startStr;
        
        auto start = parseInput(startStr);
        Piece* p = board.getPiece(start.first, start.second);
        
        if (p != nullptr && p->isWhite) {

            auto moves = p->getValidMoves(start.first, start.second, &board);

            if (moves.empty()) {
                std::cout << "That piece cannot move!\n";
                continue;
            }
            board.highlightMoves(moves);
            
            std::cout << "\n\n";
            board.printBoard();
            std::cout << "\nSelect destination: ";
            std::cin >> endStr;
            
            auto end = parseInput(endStr);
            
            board.movePiece(start.first, start.second, end.first, end.second);
            board.clearHighlights();
            
            // mimicing user move for AI by flipping the board and moving the corresponding piece
            int aiStartR = 7 - start.first;
            int aiEndR = 7 - end.first;
            board.movePiece(aiStartR, start.second, aiEndR, end.second);
            
            std::cout << "\n\n";
        } else {
            std::cout << "Invalid selection. Please choose a White piece.\n";
        }
    }
    
    return 0;
}