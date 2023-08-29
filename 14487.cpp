#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int *cost = new int[n];
    for(int i=0; i<n; ++i){
        cin >> cost[i];
    }


    int max = 0, sum = 0;;

    for(int i=0; i<n; ++i){
        if(cost[i] > cost[max]) max = i;
    }
    int tmp = cost[max];
    cost[max] = cost[0];
    cost[0] = tmp;

    for(int i=1; i<n; ++i){
        sum += cost[i];
    }

    cout << sum << endl;


    delete[] cost;
}