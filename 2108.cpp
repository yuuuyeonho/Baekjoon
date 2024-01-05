#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int* arr = new int[N];
    int sum = 0;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        sum += arr[i];
    }
    //평균
    float avg = float(sum) / N;
    cout << round(avg) + 0.0 << "\n";
    sort(arr, arr+N);
    //중앙값
    cout << arr[N/2] << endl;

    int freq[8001] = {0,};
    for(int i=0; i<N; ++i){
        int tmp = arr[i]+4000;
        freq[tmp]++;
    }

    int max = freq[0];
    for(int i=0; i<8001; ++i){
        if(max<freq[i])
            max = freq[i];
    }

    vector<int> mode;
    for(int i=0; i<8001; ++i){
        if(max == freq[i])
            mode.push_back(i-4000);
    }

    if(mode.size()==1) cout << mode[0] << endl;
    else cout << mode[1] << endl;

    //범위
    int range = arr[N-1] - arr[0];
    cout << range;

    delete[] arr;
    return 0;
}