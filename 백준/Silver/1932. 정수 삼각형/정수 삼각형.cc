#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> v(N,vector<int>(N,0));

    int value = 0;

    //입력 받아오는 코드
    for(int i = 0; i<N; i++){
        for(int j = 0; j<=i; j++){
            cin >> value;
            v[i][j] = value;
        }
    }

    vector<vector<int>> r(N,vector<int>(N,0));
    
    r[0][0] = v[0][0];

    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<=i; j++){
            r[i+1][j] = max((r[i][j]+v[i+1][j]),r[i+1][j]);
            r[i+1][j+1] = max((r[i][j]+v[i+1][j+1]),r[i+1][j+1]);
        }
    }

    int max_val = 0;
    for(int i = 0; i<N; i++){
        max_val = max(max_val,r[N-1][i]);
    }

    cout << max_val <<'\n';
    return 0;
}