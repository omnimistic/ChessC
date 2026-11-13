#pragma once
#include "Theme.h"

class Board {
public:
    Theme currentTheme = Theme::Classic;
    
    void printBoard();
};