//
//  GameBoard.hpp
//  YahtzeeFinal
//
//  Created by Heidi Wiebers on 11/30/16.
//  Copyright © 2016 Heidi Wiebers. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
class GameBoard
{
private:
    int total;
    int size;
    int scores;
    int oSize;
    int category;
    string name;
<<<<<<< HEAD
    
public:
    GameBoard();
    void Introduction();
    void TextfileGameBoard(int total[], int size, int scores[], int oSize, int category, bool outputFinalScore = false);
=======

public:
    GameBoard();
    void Introduction();
    void TextfileGameBoard(int total[], int size, int scores[], int oSize, int category, bool outputFinalScore = false );
>>>>>>> 14d75978d511427d08bdb14f225b0ad779fdae17
    void displayGameBoard(int total[], int size, int scores[], int oSize);
    int finalScore(int total[], int size);
    int FinalFinalScore (int total[]);
    
};

#endif /* GameBoard_hpp */
