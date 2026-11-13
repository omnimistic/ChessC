#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(bool white);
    std::vector<std::pair<int, int>> getValidMoves(int r, int c, Board* board) override;
};