#pragma once
#include "Theme.h"
#include "Piece.h"

class Board {

    private:

        Piece* grid[8][8]; 

    public:
        Theme currentTheme = Theme::Classic;
        
        Board();
        ~Board();
        
        void setupStartingPosition();
        void printBoard();
    };