#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <random>

#include "dp.h"
#include "brute-force.h"
#include "bracket.h"

#define MIN_SIZE 12 // 2 by default			
#define MAX_SIZE 12
#define ATTEMPS 6

#define DEBUG_ALGORITHMS 0	// to see algorithms in action 
#define PRINT_ANSWER 0		// to see results on each iteration
#define FILE_OUTPUT 0		// to write info in files

using std::string;
using std::cin;
using std::cout;
using std::clock;

float countTime(time_t, time_t);

#endif //MAIN_H