//
//  Dice.hpp
//  YahtzeeFinal
//
//  Created by Heidi Wiebers on 11/30/16.
//  Copyright © 2016 Heidi Wiebers. All rights reserved.
//

#ifndef Dice_hpp
#define Dice_hpp

#include <stdio.h>
class Dice
{
private:
    int dice;
    int size;
    int numDice;
    
public:
    Dice();
    int rollDice();
    void newRoll(int dice[], int size);
    int sumOfDice(int dice[], int numDice);
    int smallestDice(int dice[], int numDice);
    
    
    
};


#endif /* Dice_hpp */
