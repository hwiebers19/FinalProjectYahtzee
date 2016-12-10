//
//  Plays.cpp
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
using namespace std;
#include "Plays.hpp"

//creates the plays for the game
Plays::Plays()
{
    values = 0;
    dice = 0;
    size = 0;;
    sequenceLength = 0;;
    occurances = 0;
}

//counts total points in upper section
//the upper section is the dice scores for 1 through 6
void Plays::UpperSection(int values[], int dice[], int size)
{
    //
    for (int i=0; i<6; i++)
    {
        values[i]=0;
    }
    //
    for (int k=0; k<size; k++)
    {
        values [dice[k]-1]++;
    }
}

//sorts the roll of dice in order from smallest to largest
void Plays::Sort(int dice[], int size)
{
    for (int i=0; i<size; i++)
    {
        //start at 0
        int smallest=i;
        for( int j=i+1; j<size; j++)
        {
            //go through the each of the dice, check each one against the smallest and arrange the two accordingly
            if (dice[j]<dice[smallest])
            {
                smallest=j;
            }
        }
        //then switch the original smallest dice with the one that is smaller, do it each time through the all the dice
        int temp=dice[smallest];
        dice[smallest]=dice[i];
        dice[i]=temp;
    }
}

//returns true or false if dice are a run of a certain length
bool Plays::passSequence(int dice[], int size, int start, int sequenceLength)
{
    //go through all the dice, and check to see if they are a run of a certain length
    for (int i=start+1; i<start+sequenceLength; i++)
    {
        //if they aren't in a run then return false
        if (dice[i]!=dice[i-1]+1)
        {
            return false;
        }
    }
    //if they are in a run then return true
    return true;
}

//uses the function pass sequence to determine if the dice result is a small straight
//small straight is 4 dice
bool Plays::getSmallStraight(int dice[], int size)
{
    //if the function above is true for the values of dice 0-3 with a sequence length of 4
    if (passSequence(dice, size, 0,4))
    {
        return true;
    }
    //if the function above is true for the values of dice 1-4 with a sequence length of 4
    if (passSequence(dice, size, 1,4))
    {
        return true;
    }
    //if the function above is true for the values of dice 2-5 with a sequence length of 4
    if (passSequence(dice, size, 2,4))
    {
        return true;
    }
    //if the function above doesn't work in any of those conditions return false
    return false;
}

//uses the function pass sequence to determine if the dice result is a large straight
//large straight is all 5 dice
bool Plays::getLargeStraight(int dice[], int size)
{
    //if the function above is true for the values of dice 0-4 with a sequence length of 5
    if (passSequence(dice, size, 0,5))
    {
        return true;
    }
    //if the function above is true for the values of dice 1-5 with a sequence length of 5
    if (passSequence(dice, size, 1,5))
    {
        return true;
    }
    return false;
}

//determines if the values of the dice result in a full house
//full house is 2 of a kind and 3 of a different kind
bool Plays::getFullHouse(int occurences[], int size)
{
    bool hasTwo=false;
    bool hasThree= false;
    //loop through all the dice
    for(int i=0; i<size; i++)
    {
        //checks to see if there is two of a kind for the full house
        if (occurences[i]==2)
        {
            hasTwo=true;
        }
        //checks if there is three of a kind for the full house
        if (occurences[i]==3)
        {
            hasThree=true;
        }
    }
    return hasTwo && hasThree;
}
