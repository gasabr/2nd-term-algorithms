#include <iostream>
#include <fstream>
#include <cstdlib>

#include "dp.cpp"

using std::string;
using std::cin;
using std::cout;
using std::clock;

#define SIZE 12

int main(){

	std::vector<int> t;

	std::vector<float> timeDP(SIZE);

	for (int attempt = 0; attempt < 2; attempt++){
		std::string fileName;
		fileName = "results/";
    	fileName += "attempt#" + std::to_string(attempt+1)  + ".txt";

    	std::ofstream out(fileName);
    	int size = 6;
		t.resize(size + 1, rand()%10);

		time_t DP_start = clock();
		dynamicSolution(t);
		time_t DP_end = clock();
		timeDP[attempt] = float(DP_end - DP_start) / CLOCKS_PER_SEC * 1000;

		//out << "Размер: " << attempt;
		out << "Время ДП: " << timeDP[attempt] << "\n";
	}
}