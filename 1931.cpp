#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair <int, int>> p;

    int begin, end;

    for(int i=0; i<n; ++i){
        cin >> begin >> end;
        //sort 함수는 pair의 first를 기준으로 정렬한다. 끝나는 시간순으로 정렬이 필요하므로 end를 first에 저장
        p.push_back(make_pair(end, begin)); 
    }

    sort(p.begin(),p.end());

    int time = p[0].first;
    int count = 1;
    for(int i=1 ; i<n; ++i){
        if(time <= p[i].second) // second가 시작하는 시간이므로 시작 시간이 앞회의 끝나느 시간보다 크면
        {
            count++;
            time = p[i].first;
        }
    }

    cout << count;
    
}

/*
가장 먼저 끝나는 거 -> 그다음에 시작하는거 중에 가장 먼저 끝나는거 -> 반복해서 구함
즉, 끝나는 시간이 중요했다.
*/