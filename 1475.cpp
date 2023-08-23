#include<iostream>
#include<string>
using namespace std;

int main(){
    int num[10]={0,};
    string N;
    cin >> N;
    int tmp, max=0;
    int result;
    for(int i=0; i < N.length(); ++i){
        tmp = N[i] - '0';
        num[tmp]++;
    }
    for(int i=0; i< 10; ++i){
        if (i == 6 || i == 9) continue;
        else if(num[i] > num[max])
            max = i;
    }

    if((num[6] + num[9] + 1)/2  > num[max]) result = ((num[6] + num[9] + 1) / 2);
    else result = num[max];
    cout << result << endl;
}