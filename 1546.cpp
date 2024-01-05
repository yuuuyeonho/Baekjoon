#include<iostream>
using namespace std;

int main(){
    int N, i;
    double sum=0;
    cin >> N;
    int* score = new int[N];
    for(i=0; i<N; ++i)
        cin >> score[i];
    int max = score[0];
    for(i=0; i<N; ++i){
        if(max < score[i]){
            max = score[i];
        }
        sum += score[i];
    }
    double tmp = sum/max;
    tmp = tmp * 100;
    double avg = tmp/N;
    cout << avg << endl;
    delete[] score;
    return 0;
}