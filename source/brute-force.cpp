#include "brute-force.h"

void bruteForce(const vector<int>& inputOrigin){
	vector<int> inputCopy(inputOrigin);
    size_t seqSize = inputOrigin.size()-2;     // amount of matrixes + 1
    std::vector<int> row(seqSize);
	std::vector<int> solution(seqSize);
    
	long result = std::numeric_limits<long>::max();
	
    // start init of sequence (1,2..n)
    for (int i = 0; i < seqSize; i ++)
        row[i] = i+1;

    do{
		long temp = countSeq(inputCopy, row);
		inputCopy = inputOrigin;
		if (temp < result){
			result = temp;
			solution = row;
		}
	}while(std::next_permutation(row.begin(), row.end()));

#ifdef DEBUG_ALGORITHMS
    for (size_t i = 0; i < seqsAmount; ++i){
        for (size_t j = 1; j <= seqSize; ++j)
            std::cout << seq[i][j];
        cout << "\n";
    }
#endif // DEBUG_ALGORITHMS

}

/* Compute amount of operation in given sequence */
/* QUESTION: is copy of sizes */
int countSeq(vector<int>& sizes, const vector<int>& seq){
	int count = 0;
	for (size_t i = 0; i < seq.size(); i++){
		int left = seq[i]-1;
		while (sizes[left] == 0)
			left--;
		int right = seq[i]+1;
		while (sizes[right] == 0)
			right++;
		count += sizes[left] * sizes[seq[i]] * sizes[right];
		sizes[ seq[i] ] = 0;
	}
	return count;
}

/* function prints created sequnces of operations */
void showSeq(vector<int> answer){
	int i;
	vector<Bracket> seq(2*(answer.size()+1));
	int openBracketIndex;
	int closeBracketIndex;

	for (i = 0; i < answer.size(); i++){
		openBracketIndex = 2*(answer[i] - 1);
		closeBracketIndex = 2*answer[i] + 1;

		while ( seq[openBracketIndex].isInside() )
			openBracketIndex -= 2;

		while ( seq[closeBracketIndex].isInside() )
			closeBracketIndex += 2;

		seq[openBracketIndex].incCount();
		seq[closeBracketIndex].incCount();

		int j;
		for (j=openBracketIndex+1; j < closeBracketIndex; j++)
			seq[j].setInside();
	}

#ifdef PRINT_ANSWER
	int aCnt = 1;
	for (i=0; i < seq.size(); i++){
		printBrackets(seq[i].getCount(), i);
		if (i % 2 == 0){
			cout << "A" << aCnt;
			aCnt++;
		}
	}
	cout << "\n";
#endif //PRINT_ANSWER

}

void printBrackets(int count, int type){
	for (int i=0; i < count; i++)
		if (type % 2 == 0)
			cout << "(";
		else
			cout << ")";
}