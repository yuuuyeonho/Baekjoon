#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    int i;

    cin >> N;
    int numCard[N];
    for(i=0; i<N; i++){
        cin >> numCard[i];
    }

    cin >> M;
    int targetList[M];
    for(i=0; i<M; i++){
        cin >> targetList[i];
    }

    sort(numCard, numCard + N);

    int list[M];
    for(i=0; i<M; i++){
        int target = targetList[i];
        cout << upper_bound(numCard, numCard + N, target) - lower_bound(numCard, numCard + N, target) << ' ';
    }

    return 0;
}