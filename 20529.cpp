#include<iostream>
#include<string>
#include<vector>
using namespace std;

int check(string i1, string i2, string i3){
    int dst = 0;
    for(int i=0; i<4; ++i){
        if(i1[i]!=i2[i]) dst++;
    }
    for(int i=0; i<4; ++i){
        if(i2[i]!=i3[i]) dst++;
    }
    for(int i=0; i<4; ++i){
        if(i1[i]!=i3[i]) dst++;
    }
    return dst;
}

/*
int distance(vector<string> mbti, int N){
    int min = 100;
    for(int i=0; i<N; ++i){
        for(int j=0; i<N; ++j){
            if(i==j) continue;
            for(int k=0; k<N; ++k){
                if(i==k || j==k) continue;
                int tmp = check(mbti[i], mbti[j], mbti[k]);
                if(min > tmp) min = tmp;
            }
        }
    }
    return min;
}
*/

int main(){
    int T, N;
    string tmp;

    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> N;
        vector<string> mbti;
        for(int j=0; j<N; ++j){
            cin >> tmp;
            mbti.push_back(tmp);
        }
        if(N>32){
            cout << '0' << '\n';
            continue;
        }
        int min = 100;
        for(int j=0; j<N; ++j){
            for(int k=0; k<N; ++k){
            if(j==k) continue;
                for(int l=0; l<N; ++l){
                    if(j==l || k==l) continue;
                    int tmp = check(mbti[j], mbti[k], mbti[l]);
                    if(min > tmp) min = tmp;
                }
            }
        }

        cout << min << '\n';
    }

    return 0;
}