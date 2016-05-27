//
//  brute-force.hpp
//  curs-ada
//
//  Created by Gleb Abroskin on 15/05/16.
//  Copyright © 2016 Gleb Abroskin. All rights reserved.
//

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

void bruteForce(vector<int>&);
int countSeq(vector<int>, vector<int>&);
void showSeq(vector<int>);
void printBrackets (int, int);

#endif /* brute_force_hpp */

//func(int& arr, int i)