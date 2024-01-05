#include<iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int min_p=1000, min_e=1000;
    /* 배열을 쓴 풀이
    int package[M];
    int each[M];
    for(int i=0; i<M; ++i){
        cin >> package[i];
        cin >> each[i];
    }
    min_p=package[0];
    min_e=each[0];
    for(int i=0; i<M; ++i){
        if(min_p > package[i]) min_p = package[i];
        if(min_e > each[i]) min_e = each[i];
    }
    */
   // 배열을 사용하지 않고 메모리를 줄인 풀이
   int tmp1, tmp2;
   for(int i=0; i<M; ++i){
        cin >> tmp1 >> tmp2;
        if(tmp1 < min_p){
            min_p = tmp1;
        }
        if(tmp2 < min_e){
            min_e = tmp2;
        }

    }
    int need_package = N/6;
    int need_each = N%6;
    int money= min(need_package*min_p+need_each*min_e, N*min_e);
    money = min(money, (need_package+1)*min_p);

    cout << money << endl;

    return 0;
}