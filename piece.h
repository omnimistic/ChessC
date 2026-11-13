#pragma once
#include <string>

class Piece {
public:
    std::string symbol;
    bool isWhite;

    Piece(std::string sym, bool white);
    
    virtual ~Piece() = default; 
};