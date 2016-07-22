#ifndef brute_force_h
#define brute_force_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <string>

#include "bracket.h"

using std::vector;
using std::cout;

typedef vector<int> solution;

void bruteForce(const vector<int>&);
int countSeq(vector<int>&, const vector<int>&);
void showSeq(vector<int>);
void printBrackets (int, int);

#endif /* brute_force_h */