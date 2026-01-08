#include<iostream>
#include<vector>
#define SIZE 201
using namespace std;

int list[SIZE][SIZE]={0,};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        list[a][b]=1;
        list[b][a]=1;
    }

    int ret=0;
    for(int i=1;i<=n-2;i++)for(int j=i+1;j<=n-1;j++)for(int k=j+1;k<=n;k++)
        if(!list[i][j] && !list[j][k] && !list[i][k] ) ret++;
    cout<<ret<<'\n';
}