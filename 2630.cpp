#include<iostream>
using namespace std;

int white = 0;
int blue = 0;
int paper[129][129];

void explore(int x, int y, int n){
    int first_color = paper[x][y];
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(paper[i][j] != first_color){
                explore(x,y,n/2);
                explore(x+n/2,y,n/2);
                explore(x,y+n/2,n/2);
                explore(x+n/2,y+n/2,n/2);
                return;
            }
        }
    }
    if(first_color == 1) blue++;
    else white++;
}


int main() {
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> paper[i][j];
        }
    }

    explore(0, 0, N);

    cout << white << "\n" << blue;
}