#include "bracket.h"

Bracket::Bracket()
{
    count = 0;
    inside = 0;
}

bool Bracket::isInside(){ return inside; }

void Bracket::setInside() { inside = true; }

int Bracket::getCount() { return count; }

void Bracket::incCount() { count++; }

void Bracket::setCount( int count ) { this->count += count; }