#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int N;
    cin >> N;
    int *tree = new int[N];
    int max , tmp, day=1;
    
    for(int i=0; i<N; ++i){
        cin >> tree[i];
    }
    
    sort(tree, tree+N, greater<int>());

    int treegrow = 1;

    for(int i=0; i<N; ++i){
        day++;
        treegrow--;
        if (treegrow < tree[i]) treegrow = tree[i];
    }

    cout << day + treegrow;

    delete[] tree;
}