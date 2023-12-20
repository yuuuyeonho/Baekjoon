#include<iostream>
#include<vector>
using namespace std;

/*
struct record{
    int n;
    struct record * left;
    struct record * right;
};


void add(){
    struct record * p;

}
*/

int main(){
    vector<int> v;

    int n, i, j;
    cin >> n;
    for(i = n; i>0; --i){
        cin >> n;
        if(n <=0){
            if(v.empty()==1)    cout << 0;
            else{
                cout << v. << endl;
                }
        }
        else {
            if(v.empty() == 0) v.push_back(n);
            else{
                for(j=0; j< v.size(); ++i){
                    if (v[j]>n) {
                        v.insert(v.begin()+j,n);
                    }
                }
            }
        }
    }

}