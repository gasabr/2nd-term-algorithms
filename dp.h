#ifndef DP_H
#define DP_H

#include <stdio.h>
#include <vector>
#include <iostream>

using std::vector;

typedef vector<vector<int> > table;

int dynamicSolution(vector<int>&);

void showBrackets(table&, int, int);

using std::vector;
using std::cout;

#endif //DP_H