#pragma once
#include <string>
#include <vector>
#include <utility>

class Board; 

class Piece {
public:
    std::string symbol;
    bool isWhite;

    Piece(std::string sym, bool white);

    virtual ~Piece() = default; 

    virtual std::vector<std::pair<int, int>> getValidMoves(int r, int c, Board* board) = 0;
};