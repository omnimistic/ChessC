#pragma once
#include "Theme.h"
#include "../pieces/Piece.h"
#include <vector>
#include <utility>

class Board {
private:
    Piece* grid[8][8]; 
    bool highlighted[8][8];

public:
    Theme currentTheme = Theme::Classic;
    
    Board();
    ~Board(); 
    
    void setupStartingPosition();
    void printBoard();
    
    Piece* getPiece(int r, int c);
    void movePiece(int startR, int startC, int endR, int endC);
    void highlightMoves(std::vector<std::pair<int, int>> moves);
    void clearHighlights();
};