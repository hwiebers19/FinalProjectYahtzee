//
//  GameBoard.cpp
//  YahtzeeFinal
//
//  Created by Heidi Wiebers on 11/30/16.
//  Copyright © 2016 Heidi Wiebers. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <vector>
using namespace std;
#include "GameBoard.hpp"

//creates a gameboard
GameBoard::GameBoard()
{
    total = 0;
    size = 0;
    scores = 0;
    oSize = 0;
    category = 0;
    name;
}

//welcomes the user to the game
void GameBoard::Introduction()
{
    
    cout << "  **********************************" << endl;
    cout << "  *             YAHTZEE            *" << endl;
    cout << "  **********************************" << endl;
    cout << endl;
    cout << "  Welcome to the game of Yahtzee!!!"<<endl;
    cout << "   In order to win you need to "<<endl;
    cout << "      get 250 points or more."<<endl;
    cout << "        Have fun playing"<<endl;
    cout<< "If you attempt to enter your roll into  "<<endl;
    cout<< " a category that it does not fit into,"<<endl;
    cout << "     then you will be given"<<endl;
    cout << "          a score of 0."<<endl;
    cout << endl;
    
    cout<<"Enter your name: ";
    cin>>name;
    
    cout << endl << endl;
}


//displayes the gameboard
void GameBoard::displayGameBoard(int total[], int size, int scores[], int oSize)
{
    
    
    int category=0;
    
    //User picks category for scoring
    cout << "Under what category would you like to record your score: "<<endl;
    cout << "1 - Ones: " <<endl;
    cout << "2 - Twos: " <<endl;
    cout << "3 - Threes: " <<endl;
    cout << "4 - Fours: " <<endl;
    cout << "5 - Fives: " <<endl;
    cout << "6 - Sixes: " <<endl;
    cout << "7 - 3 of a Kind (3 of the same number): " <<endl;
    cout << "8 - 4 of a Kind (4 of the same number): " <<endl;
    cout << "9 - Full House (3 of a kind and a pair): " <<endl;
    cout << "10 -Small Straight (Sequence of four): " <<endl;
    cout << "11 -Large Straight  (Sequence of five): " <<endl;
    cout << "12 -Yahtzee  (Five of the same number): " <<endl;
    cout << "13 -Chance (Any combination): " <<endl;
    
    //get choice from user
    cout << "Choice (1-13): "<<endl;
    cin >> category ;
    cout <<endl;
    
    //make sure the category is valid
    while (total[category-1]!=0)
    {
        
        cout<<"Category has already been selected, please choose a different category"<<endl;
        
        cin>>category;
        
    }
    
    //set the array of total[] points to equal the score at the same index, the index being the category they choose-1
    total [category-1]= scores[category-1];
    
    
    //Displays the current points
    cout << "1 - Ones: " << total[0] << "  "<<endl;
    cout << "2 - Twos: " << total[1] << "  "<<endl;
    cout << "3 - Threes: " << total[2] << "  "<<endl;
    cout << "4 - Fours: " << total[3] << "  "<<endl;
    cout << "5 - Fives: " << total[4] << "  "<<endl;
    cout << "6 - Sixes: " << total[5] << "  "<<endl;
    cout << "7 - 3 of a Kind: " << total[6] << "  "<<endl;
    cout << "8 - 4 of a Kind: " << total[7] << "  "<<endl;
    cout << "9 - Full House: " << total[8] << "  "<<endl;
    cout << "10 -Small Straight: " << total[9] << "  "<<endl;
    cout << "11 -Large Straight: " << total[10] << "  "<<endl;
    cout << "12 -Yahtzee: " << total[11] << "  "<<endl;
    cout << "13 -Chance: " << total[12] << "   "<<endl;
    cout <<endl;
    
    TextfileGameBoard(total, size, scores, oSize,category);
    
}


//displayes the gameboard for the user using a txt file
void GameBoard::TextfileGameBoard(int total[], int size, int scores[], int oSize,int category, bool outputFinalScore)
{
    
    
    //outputs a new textfile
    ofstream output;
    
    //opens that text file and declares name
    output.open ("GameBoard.txt", fstream::out);
    
   
    output << "Name of user: " << name << endl;

    output << " "<<endl;
    
    
    //User picks category for scoring
    output << "CATEGORIES:" <<endl;
    output << "1 - Ones: " <<endl;
    output << "2 - Twos: " <<endl;
    output << "3 - Threes: " <<endl;
    output << "4 - Fours: " <<endl;
    output << "5 - Fives: " <<endl;
    output << "6 - Sixes: " <<endl;
    output << "7 - 3 of a Kind (3 of the same number): " <<endl;
    output << "8 - 4 of a Kind (4 of the same number): " <<endl;
    output << "9 - Full House (3 of a kind and a pair): " <<endl;
    output << "10 -Small Straight (Sequence of four): " <<endl;
    output << "11 -Large Straight  (Sequence of five): " <<endl;
    output << "12 -Yahtzee  (Five of the same number): " <<endl;
    output << "13 -Chance (Any combination): " <<endl;
    
    output << " "<<endl;
    
    
    
    //Displays the current points
    output << "CURRENT SCORES: " <<endl;
    output << "1 - Ones: " << total[0] << "  "<<endl;
    output << "2 - Twos: " << total[1] << "  "<<endl;
    output << "3 - Threes: " << total[2] << "  "<<endl;
    output << "4 - Fours: " << total[3] << "  "<<endl;
    output << "5 - Fives: " << total[4] << "  "<<endl;
    output << "6 - Sixes: " << total[5] << "  "<<endl;
    output << "7 - 3 of a Kind: " << total[6] << "  "<<endl;
    output << "8 - 4 of a Kind: " << total[7] << "  "<<endl;
    output << "9 - Full House: " << total[8] << "  "<<endl;
    output << "10 -Small Straight: " << total[9] << "  "<<endl;
    output << "11 -Large Straight: " << total[10] << "  "<<endl;
    output << "12 -Yahtzee: " << total[11] << "  "<<endl;
    output << "13 -Chance: " << total[12] << "   "<<endl;
    output <<endl;
    
    if ( outputFinalScore )
    {
        output << "Your Final Score is: " << FinalFinalScore(total);
    }
    //closes file
    output.close();
    
}


//adds up all points listed in gameboard
//returns final score
int GameBoard::finalScore(int total[], int size)
{
    
    int points=0;
    for (int i=0; i<size; i++)
    {
        points+=total[i];
    }
    return points;
}

int GameBoard:: FinalFinalScore (int total[])
{
    int tt=0;
    
    //to calculate the subtotal
    for (int r=0; r<6; r++)
    {
        tt+=total[r];
    }
   
    // tells the user their total points and if they won or not
    int FinalPointTotal=0;
    if (tt>62)
    {
        FinalPointTotal=finalScore(total,13)+35;
    }
    else
    {
        FinalPointTotal=finalScore(total,13);
    }
    return FinalPointTotal;

}
