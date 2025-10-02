#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin>>N)) return 0;

    vector<vector<int>> v(N,vector<int>(3,0));

    vector<vector<int>> r(N,vector<int>(3,0));

    // RGB맵 2차원벡터로 받아오기
    for(int i = 0; i<N; i++){
        int value;
        
        //R 값 넣기
        cin >> value;
        v[i][0] = value;
        
        //G값 넣기
        cin >> value;
        v[i][1] = value;
        
        //B값 넣기
        cin >> value;
        v[i][2] = value;
    }

    r[0][0] = v[0][0]; r[0][1] = v[0][1]; r[0][2] = v[0][2];

    for(int i = 1; i<N; i++){

        //R 정하는 코드
        if(r[i-1][1] <= r[i-1][2]){
            r[i][0] = r[i-1][1] + v[i][0];
        }
        else{
            r[i][0] = r[i-1][2] + v[i][0];
        }

        //G 정하는 코드
        if(r[i-1][0] <= r[i-1][2]){
            r[i][1] = r[i-1][0] + v[i][1];
        }
        else{
            r[i][1] = r[i-1][2] + v[i][1];
        }

        //B 정하는 코드
        if(r[i-1][0] <= r[i-1][1]){
            r[i][2] = r[i-1][0] + v[i][2];
        }
        else{
            r[i][2] = r[i-1][1] + v[i][2];
        }

    }

    // 결과
    cout << min({r[N-1][0], r[N-1][1], r[N-1][2]}) << '\n';
    return 0;
    

    
}