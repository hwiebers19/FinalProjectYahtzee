//
//  Dice.cpp
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
#include "Dice.hpp"


Dice::Dice()
{
    dice = 0;
    size = 0;
    numDice = 0;
}

//creates a dice displays the dice to the player
void Dice:: displayDice (int dice[], int size)
{
    //loops to display each index of the dice[] array
    for (int i=0; i<size; i++)
    {
        cout<<dice[i]<<" ";
    }
    cout<<endl;
}

//rolls the dice
//gives random number 1-6 for dice
int Dice::rollDice()
{
    return (rand()%6)+1;
}

//assigns random value
//generated in roll dice function to each of the five dice
void Dice::newRoll(int dice[], int size)
{
    //assigns the dice values to each of the five dice in the array dice[]
    for (int i=0; i<size; i++)
    {
        dice[i]=rollDice();
    }
}

//calculates the sum of dice
int Dice::sumOfDice(int dice[], int numDice)
{
    //use a loop add up each value of each index of dice[]
    int sum=0;
    for (int i=0; i<numDice; i++)
    {
        sum+=dice[i];
    }
    return sum;
}

//finds the smallest dice
int Dice::smallestDice(int dice[], int numDice)
{
    //loop through each of the dice... all indexes of dice[]
    int smallest=10;
    for (int i=0; i<numDice;i++)
    {
        //check each index to find the smallest value of dice
        if(dice[i]<smallest)
        {
            smallest=dice[i];
        }
    }
    return smallest;
}


    
    
    
