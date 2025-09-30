#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    const int MOD = 15746;

    if (n==1){
        cout << 1 << '\n';
        return 0;
    }
    if(n==2){
        cout << 2 << '\n';
        return 0;
    }

    int a = 1, b = 2;

    for(int i = 3; i <=n; ++i){
        int c = (a + b)%MOD;
        a = b;
        b = c;
        
    }

    cout << b << '\n';
    return 0;
}