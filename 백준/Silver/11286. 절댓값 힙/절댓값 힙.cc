#include <bits/stdc++.h>

using namespace std;

struct Cmp{
    bool operator()(int a, int b) const{

        long long aa = llabs((long long)a);
        long long bb = llabs((long long)b);
    
        if (aa != bb) return aa > bb;
        return a > b;
    }       
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int value;
    priority_queue<int, vector<int>, Cmp> pq;
    
    for(int i = 0; i < N; ++i){
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

    return 0;
    
}

