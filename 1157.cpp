#include<iostream>
#include<string>
using namespace std;

int main(){
    char c[1000005];
    cin >> c;
    int cnt[26]={0,};
    int tmp, max=0;
    int l = strlen(c);
    char ans;
    for(int i = 0; i<l; ++i){
        if(c[i] < 'A'){tmp = c[i] - 'a'; cnt[tmp]++;}
        else{tmp = c[i] - 'A'; cnt[tmp]++;}
    }
    for(int i = 0; i < 26; ++i){
        if(cnt[i] > cnt[max]) {max = i; ans = 'A'+max;}
        else if(cnt[i] == cnt[max]) ans = '?';
    }
    cout << ans;

    return 0;
}