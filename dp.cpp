#include "dp.h"

int dynamicSolution(vector<int>& sizeOfMatrix) {
    int n = (int)sizeOfMatrix.size();
    vector<vector<int> > m;
    m.resize(n, vector<int>(n ,0));

    vector<vector<int> > divideAt;
    divideAt.resize(n, vector<int>(n, 0));

    //динамически вычислить оптимальную стратегию, занести в массив s действие,
    //на котором мы делим последовательность скобками
    for (int l=2; l <= n; l++){
        for (int i = 1; i < (n-l+1); i++){
            int j = i + l - 1;
            m[i][j] = 999999999;

            for (int k = i; k < j; k++){
                //дин
                int temp = m[i][k] + m[k+1][j] + sizeOfMatrix[i-1]*sizeOfMatrix[k]*sizeOfMatrix[j];
                if (temp < m[i][j]){
                    m[i][j] = temp;
                    divideAt[i][j] = k;
                }
            }
        }
    }

#ifdef PRINT_ANSWER
    showBrackets(divideAt, 1, n - 1);
    cout << "\n";
#endif //PRINT_ANSWER

    //вывод таблицы вариантов
#ifdef MY_DEBUG
    for(int i=1; i < n; i++){
        for(int j=0; j < n; j++){
            if (i <= j){
                cout.width(6);
                cout << m[i][j];
            }
            else
                cout << "      ";
        }
        cout << "\n";
    }
    //вывод таблицы расстановки скобок
    for (int i = 1; i < n; ++i){
        for (size_t j = 0; j < n; ++j){
            cout.width(3);
            cout << divideAt[i][j];
        }
        cout << "\n";
    }
#endif

    return m[1][n-1];
}

void showBrackets(table& s, int i, int j){
    if (i == j)
        cout << "A" << i;
    else{
        cout << "(";
        showBrackets(s, i, s[i][j]);
        showBrackets(s, s[i][j]+1, j);
        cout << ")";
    }
}