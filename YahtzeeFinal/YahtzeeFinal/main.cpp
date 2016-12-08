//
//  main.cpp
//  YahtzeeFinal
//
//  Created by Heidi Wiebers on 11/15/16.
//  Contributed by Megan Bruening
//  Copyright © 2016 Heidi Wiebers & Megan Bruening. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;
#include "Dice.hpp"
#include "GameBoard.hpp"
#include "Plays.hpp"


int main()
{
    // Welcome the user
    GameBoard GB;
    GB.Introduction();
    
    // Define variables
    const int numDice=5;
    int roll=9;
    char reRoll;
    srand(time(NULL));
    int dice[numDice];
    int Upper[6];
    
    const int numSec=13;
    int total[numSec];
    int scores [numSec];
    
    // gives the player 13 turns
    for (int k=0; k<13; k++)
    {
        total [k]=0;
    }
    // gives the player the dice in the roll and lets him keep his dice or roll again
    for (int t=0; t<13; t++)
    {
        // calls the function to roll a new set of dice
        Dice d;
        d.newRoll(dice, numDice);
        
        for (int p=1; p<3; p++)
        {
            // calls the function to display all 5 dice
            d.displayDice(dice, numDice);
            cout<<endl;
            cout<<"Do you want to keep any of these dice in this roll? "<<endl;
            cout<<"Type 0 to keep and 1 to re-roll all: ";
            cin>>roll;
            // each turn you get the opportunity to roll 3 times
            while (roll!=1 && roll!=0)
            {
                cout<<"Choice is invalid, please enter 1 for re-roll all and 0 to keep some "<<endl;
                cin>>roll;
                
            }
            // reroll all dice
            if (roll==1)
            {
                d.newRoll (dice, numDice);
            }
            //  keeps dice
            if (roll==0)
            {
                for (int j=0; j<numDice; j++)
                {
                    cout<< "Do you want to re-roll dice "<<j+1<<" (y/n): ";
                    cin>>reRoll;
                    // calls function to reroll specific dice
                    while (reRoll!='y' && reRoll!='n')
                    {
                        cout<<"That is an invalid choice, please choose y for re-roll and n to keep"<<endl;
                        cin>>reRoll;
                    }
                    // rerolls dice
                    if(reRoll=='y')
                    {
                        dice[j]=d.rollDice();
                    }
                }
            }
            
            
        }
        cout<<endl;
        
        d.displayDice (dice,numDice);
        
        cout<<endl;
        
        // tells the player the outcome of his roll
        Plays P;
        P.UpperSection (Upper, dice, numDice);
        for (int h=0; h<6;h++)
        {
            cout<< h+1<<" occurs "<<Upper[h]<<endl;
        }
        
        for (int k=0; k<13; k++)
        {
            scores [k]=0;
        }
        
        for (int k=0; k<13; k++)
        {
            if (k<6)
            {
                scores[k]=(k+1)*Upper[k];
            }
        }
        cout<<endl;
        
        // allows the user to put the dice into the category of choice
        for (int i=0; i<numDice; i++)
        {
            // category 3 of a kind
            if (Upper[i]>=3)
            {
                scores[6]=d.sumOfDice(dice, numDice);
            }
            // category 4 of a kind
            if (Upper[i]>=4)
            {
                scores[7]=d.sumOfDice(dice, numDice);
            }
            // category Yahtzee and gives user 50 points when roll a second Yahtzee
            if (Upper[i]>=5)
            {
                if(total[11]>0)
                {
                    scores[11]= d.sumOfDice(dice, numDice)+50;
                }
                else
                {
                    scores[11]= 50;
                }
            }
            
            
        }
        // sorts the dice to check if it is a straight
        P.Sort(dice, numDice);
        // category small straight
        if (P.getSmallStraight(dice, numDice))
        {
            scores [9]= 30;
        }
        // category large straight
        if (P.getLargeStraight(dice, numDice))
        {
            scores[10]= 40;
        }
        // category full house
        if (P.getFullHouse(Upper, numDice))
        {
            scores [8]= 25;
        }
        scores[12]=d.sumOfDice(dice, numDice);
        
    
        GB.displayGameBoard(total, numSec, scores, numDice);
        GB.TextfileGameBoard(total, numSec, scores, numDice);

    }
    
    
    
    int tt=0;
    
    //to calculate the subtotal
    for (int r=0; r<6; r++)
    {
        tt+=total[r];
    }
    cout<< "Your Upper Section Subtotal is: "<<tt;
    
    cout<<endl;
    // tells the user their total points and if they won or not
    int FinalPointTotal=0;
    if (tt>62)
    {
        FinalPointTotal=GB.finalScore(total,13)+35;
    }
    else
    {
        FinalPointTotal=GB.finalScore(total,13);
    }
    cout<<"Your final score is: "<<FinalPointTotal<<endl;
    if(FinalPointTotal>= 250)
    {
        cout<<"Congradulations, you win!!"<<endl;
    }
    else
    {
        cout<<"Sorry you didn't get enough points to win"<<endl;
    }
    
    
    return 0;
}
