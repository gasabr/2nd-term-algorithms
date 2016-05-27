//
// Created by Gleb Abroskin on 19/05/16.
//

#include "bracket.h"

bool Bracket::isInside(){ return inside; }
void Bracket::setInside() { inside = 1; }
int Bracket::getCount() { return count; };
void Bracket::incCount() { count++; }
void Bracket::setCount(int count) { this->count += count; }

Bracket::Bracket(){
    count = 0;
    inside = 0;
}



