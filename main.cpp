#include <iostream>
#include "Board.h"
#include "Theme.h"

int main() {
    std::cout << "Hi LOL! \n\n";
    
    Board board;
    board.currentTheme = Theme::Wood; 
    
    board.setupStartingPosition();
    
    board.printBoard();
    
    return 0;
}