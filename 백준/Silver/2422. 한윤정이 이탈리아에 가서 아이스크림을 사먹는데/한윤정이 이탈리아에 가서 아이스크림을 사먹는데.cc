#include<iostream>
#include<vector>
#define SIZE 200
using namespace std;

vector<vector<int>> list(201);

bool Check(int a,int b,int c){
    for(int i=0;i<list[a].size();i++) if(list[a][i]==b || list[a][i]==c) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    int ret=0;
    for(int i=1;i<=n-2;i++)for(int j=i+1;j<=n-1;j++)for(int k=j+1;k<=n;k++)
        if(Check(i,j,k) && Check(j,i,k) && Check(k,i,j)) ret++;
    cout<<ret<<'\n';
}