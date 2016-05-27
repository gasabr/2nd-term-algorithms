#include "main.h"

int main(){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,40);

	std::vector<int> t;
	std::vector<float> timeDP;
	std::vector<float> timeBF;
	

	for (int attempt = 0; attempt < ATTEMPS; attempt++){
		timeDP.resize(MAX_SIZE);
		timeBF.resize(MAX_SIZE);

		std::string fileName;
		fileName = "results/";
    	fileName += "attempt#" + std::to_string(attempt+1)  + ".txt";

    	std::ofstream out(fileName);
    	int size = 2;
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

			out << "Размер: " << size << "\n";
			out << "Время ДП: " << timeDP.at(size-2) << "\n";
			out << "Время ПП: " << timeBF.at(size-2) << "\n";

			out << "\n";
			
			size++;
    	}
    	t.clear();
    	timeDP.clear();
	}
}