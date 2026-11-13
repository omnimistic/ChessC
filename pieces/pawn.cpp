#include "Pawn.h"
#include "../core/Board.h" // We can safely include the full Board file here

Pawn::Pawn(bool white) : Piece("P", white) {}

std::vector<std::pair<int, int>> Pawn::getValidMoves(int r, int c, Board* board) {
    std::vector<std::pair<int, int>> moves;
    
    // White moves UP the grid (decreasing row index), Black moves DOWN
    int dir = isWhite ? -1 : 1; 

    // Forward 1 square
    if (r + dir >= 0 && r + dir < 8 && board->getPiece(r + dir, c) == nullptr) {
        moves.push_back({r + dir, c});
        
        // Forward 2 squares (Only allowed if on starting rank: White=6, Black=1)
        if ((isWhite && r == 6) || (!isWhite && r == 1)) {
            if (board->getPiece(r + 2 * dir, c) == nullptr) {
                moves.push_back({r + 2 * dir, c});
            }
        }
    }
    return moves;
}