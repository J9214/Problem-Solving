#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int n,m; cin >> n >> m;
    vector<vector<int>> vec(n,vector<int>(m,0));
    
    for(int k = 0 ; k < 2; k++)
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                int d; cin >> d;
                vec[i][j]+=d;
            }
        }

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cout << vec[i][j] << ' ';
        }
        cout << '\n';
    }

}