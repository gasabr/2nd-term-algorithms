#include "main.h"

int main(){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,40);

	std::vector<int> t;
	std::vector<float> timeDP;
	std::vector<float> timeBF;

	std::vector<float> avgTimeDP(MAX_SIZE);
	std::vector<float> avgTimeBF(MAX_SIZE);
	
	for (int attempt = 0; attempt < ATTEMPS; attempt++){
		timeDP.resize(MAX_SIZE);
		timeBF.resize(MAX_SIZE);

		std::string fileName;
		fileName = "results/";
    	fileName += "attempt#" + std::to_string(attempt+1)  + ".txt";

    	std::ofstream out(fileName);
    	int size = 2;

    	out << "Размер" << "\t\tВремя ДП" << "\tВремя ПП: " << "\n";

    	while (size < MAX_SIZE-1){
    		
    		t.resize(size + 1);

    		for (int i=0; i < size; i++)
    			t[i] = dist(gen);
 

			time_t DP_start = clock();
			dynamicSolution(t);
			time_t DP_end = clock();

			timeDP.at(size-2) = float(DP_end - DP_start); 	//количество тактов
			timeDP.at(size-2) /= CLOCKS_PER_SEC;			//количество секунд
			timeDP.at(size-2) *= 1000;						//перевод в мc

			time_t BF_start = clock();
			bruteForce(t);
			time_t BF_end = clock();

			timeBF.at(size-2) = float(BF_end - BF_start); 	//количество тактов
			timeBF.at(size-2) /= CLOCKS_PER_SEC;			//количество секунд
			timeBF.at(size-2) *= 1000;						//перевод в мc

			avgTimeDP.at(size-2) += timeDP.at(size-2);
			avgTimeBF.at(size-2) += timeBF.at(size-2);

			cout.width(6);
			out << size << "\t\t";
			cout.width(10);
			out << timeDP.at(size-2)<< "\t\t";
			cout.width(10);
			out  << timeBF.at(size-2) << "\n";

			out << "\n";
			
			size++;
    	}
    	t.clear();
    	timeDP.clear();
	}

	std::ofstream outAVG("results/avg.txt");
	std::ofstream forExcel("results/forExcel.txt");
	int i = 2;
	while (i < MAX_SIZE-1){
		outAVG << "Размер: " << i << "\n";
		outAVG << "Среднее время для алгоритма\n";
		outAVG << "ДП: " << avgTimeDP.at(i-2) << "\n";
		outAVG << "ПП: " << avgTimeBF.at(i-2) << "\n";
		forExcel << avgTimeDP.at(i-2) << "\t" << avgTimeBF.at(i-2) << "\n";
		outAVG << "\n";
		i++;
	}
}