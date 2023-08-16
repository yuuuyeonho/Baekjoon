#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int matrixA[m][n];
    int matrixB[m][n];

    for(int i=0; i < m; ++i){
        for(int j=0; j<n; ++j){
            cin >> matrixA[i][j];
        }
    }

    for(int i=0; i < m; ++i){
        for(int j=0; j<n; ++j){
            cin >> matrixB[i][j];
        }
    }

    int matrixS[m][n];
    
    for(int i=0; i < m; ++i){
        for(int j=0; j<n; ++j){
            matrixS[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    for(int i=0; i < m; ++i){
        for(int j=0; j<n; ++j){
            if (matrixS[i][j] > 100) matrixS[i][j] = 100;
            cout << matrixS[i][j] << ' ';
        }
        cout << endl;
    }
}