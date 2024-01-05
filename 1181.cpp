#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int N, i;
    cin >> N;
    string tmp;
    pair<int,string> p[N];
    for(i=0; i<N; ++i){
        cin >> tmp;
        p[i].first = tmp.length();  //sort를 위해 문자열의 길이를 first로
        p[i].second = tmp;
    }
    sort(p,p+N);    //pair를 sort시 first기준으로 먼저 정렬, second는 후정렬
    tmp = p[0].second;
    cout << p[0].second << endl;
    for(i=1; i<N; ++i){
        if(p[i].second == tmp)  continue; //겹치는 문자 빼기
        cout << p[i].second << endl;
        tmp = p[i].second;
    }
    return 0;
}