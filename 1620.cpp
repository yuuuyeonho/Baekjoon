#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cctype>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    map<string, int> pokemon;
    vector<string> name;
    int N, M;
    string tmp;
    int input_num;
    cin >> N >> M;
    for(int i=1; i<N+1; ++i){
        cin >> tmp;
        name.push_back(tmp);
        pokemon.insert(make_pair(tmp,i));
    }

    for(int i=0; i<M; ++i){
        cin >> tmp;
        if(atoi(tmp.c_str())!=0){
            input_num = stoi(tmp);
            cout << name[input_num-1] << '\n';
        }
        else{
            cout << pokemon[tmp] << '\n';
        }
    }
}