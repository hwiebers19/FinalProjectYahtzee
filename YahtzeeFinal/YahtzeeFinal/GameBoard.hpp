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
//Gameboard class
//this class totals the final score and outputs the gameboard
class GameBoard
{
private:
    int total;
    int size;
    int scores;
    int oSize;
    int category;
    string name;

    
public:
    GameBoard();
    void Introduction();
    void TextfileGameBoard(int total[], int size, int scores[], int oSize, int category, bool outputFinalScore =false);
    void displayGameBoard(int total[], int size, int scores[], int oSize);
    int finalScore(int total[], int size);
    int FinalFinalScore (int total[]);
    
};

#endif /* GameBoard_hpp */
