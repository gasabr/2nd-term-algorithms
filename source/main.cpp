#include "main.h"

int main(){
/* Random engine */
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,40);

    std::vector<int> t;

/* Storing time on each attempt */
	std::vector<float> timeDP;
	std::vector<float> timeBF;

/* Storing average time */
	std::vector<float> avgTimeDP(MAX_SIZE);
	std::vector<float> avgTimeBF(MAX_SIZE);
	
	for (int attempt = 0; attempt < ATTEMPS; attempt++){
		/* To fix strange error with sizes of vectors */
		timeDP.resize(MAX_SIZE);
		timeBF.resize(MAX_SIZE);

		/* Create new files for each attempt */
		std::string fileName;
		fileName = "../results/";
    	fileName += "attempt#" + std::to_string(attempt+1)  + ".txt";

    	std::ofstream out(fileName);
    	int size = MIN_SIZE;

    	out << "Размер" << "\t\tВремя ДП" << "\tВремя ПП: " << "\n";

    	while (size < MAX_SIZE-1){
    		
    		t.resize(size + 1);

    		for (int i=0; i < size; i++)
    			t[i] = dist(gen);
 
    		/* Counting time to dynamic programming */
			time_t DP_start = clock();
			dynamicSolution(t);
			time_t DP_end = clock();

			/* Counting time to brute force */
			time_t BF_start = clock();
			bruteForce(t);
			time_t BF_end = clock();

			timeDP.at(size) = countTime(DP_start, DP_end);
			timeBF.at(size) = countTime(BF_start, BF_end);

#ifdef FILE_OUTPUT

			/* fill vectors with time */
			avgTimeDP.at(size) += timeDP.at(size);
			avgTimeBF.at(size) += timeBF.at(size);

			cout.width(6);
			out << size << "\t\t";
			cout.width(10);
			out << timeDP.at(size) << "\t\t";
			cout.width(10);
			out  << timeBF.at(size) << "\n";

			out << "\n";
#endif // FILE_OUTPUT
			
			size++;
    	}
    	t.clear();
    	timeDP.clear();
	}

#ifdef FILE_OUTPUT
	std::ofstream outAVG("../results/avg.txt");
	std::ofstream forExcel("../results/forExcel.txt");
	int i = 2;
	while (i < MAX_SIZE-1){
		outAVG << "Размер: " << i << "\n";
		outAVG << "Среднее время для алгоритма\n";
		outAVG << "ДП: " << avgTimeDP.at(i) / ATTEMPS << "\n";
		outAVG << "ПП: " << avgTimeBF.at(i) / ATTEMPS << "\n";
		forExcel << avgTimeDP.at(i) / ATTEMPS << "\t" << avgTimeBF.at(i) / ATTEMPS << "\n";
		outAVG << "\n";
		i++;
	}
#endif // FILE_OUTPUT
}

float countTime(time_t start, time_t end)
{
	return float(start - end) / CLOCKS_PER_SEC * 1000;
}