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
    
}
//counts total points in upper section
//the upper section is the dice scores for 1 through 6
void Plays::UpperSection(int values[], int dice[], int size)
{
    
}
//sorts the roll of dice in order from smallest to largest
void Plays::Sort(int dice[], int size)
{
    
}
//returns true or false if dice are a run of a certain length
bool Plays::passSequence(int dice[], int size, int start, int sequenceLength)
{
    return false;
}
//uses the function pass sequence to determine if the dice result is a small straight
//small straight is 4 dice
bool Plays::getSmallStraight(int dice[], int size)
{
    return false;
}
//uses the function pass sequence to determine if the dice result is a large straight
//large straight is all 5 dice
bool Plays::getLargeStraight(int dice[], int size)
{
    return false;
}
//determines if the values of the dice result in a full house
//full house is 2 of a kind and 3 of a different kind
bool Plays::getFullHouse(int occurances[], int size)
{
    return false;
}