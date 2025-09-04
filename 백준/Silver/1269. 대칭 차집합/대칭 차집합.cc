#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;
    
    set<int> sa;
    set<int> sb;
    int value;
    
    while(N--){
        
        cin >> value;
        sa.insert(value);
    }

    while(M--){
        
        cin >> value;
        sb.insert(value);
    }

    int ca = 0;
    int cb = 0;

    for(auto x : sa){
        if(sb.find(x) == sb.end()){
            ++ca;
        }
    }
    for(auto x : sb){
        if(sa.find(x) == sa.end()){
            ++cb;
        }
    }

    cout << ca + cb;
    
    return 0;
}