//
//  Plays.hpp
//  YahtzeeFinal
//
//  Created by Heidi Wiebers on 11/30/16.
//  Copyright © 2016 Heidi Wiebers. All rights reserved.
//

#ifndef Plays_hpp
#define Plays_hpp

#include <stdio.h>

class Plays{
private:
    int values;
    int dice;
    int size;
    int sequenceLength;
    int occurances;
    
public:
    Plays();
    void UpperSection(int values[], int dice[], int size);
    void Sort(int dice[], int size);
    bool passSequence(int dice[], int size, int start, int sequenceLength);
    bool getSmallStraight(int dice[], int size);
    bool getLargeStraight(int dice[], int size);
    bool getFullHouse(int occurances[], int size);
    
};

#endif /* Plays_hpp */
