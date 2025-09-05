#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    priority_queue<int,vector<int>, greater<int>> pq;
    int value;
    
    for(int i = 0; i < N*N; ++i){
        cin >> value;
        pq.push(value);
        if(i>=N){
            pq.pop();
        }
    }

    cout << pq.top() << '\n';

    return 0;
    
}