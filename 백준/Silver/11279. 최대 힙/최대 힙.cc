#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int value;
    priority_queue<int> pq;
    
    for(int i = 0; i < N; i++){
        cin >> value;
        if(value == 0){
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
        else{
            pq.push(value);
        }
    }
}