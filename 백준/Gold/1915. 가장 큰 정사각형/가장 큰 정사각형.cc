#include<iostream>
#include<algorithm>
#define SIZE 1000
using namespace std;

int arr[SIZE][SIZE]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,m,ret=0;; cin>>n>>m;

    char c; 
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        cin>>c;
        arr[i][j]=c-'0';
        ret=max(arr[i][j],ret);
        if(!arr[i][j]) continue;

        // 위, 왼쪽, 대각선 
        if(0<i && arr[i-1][j] && 0<j && arr[i][j-1] && arr[i-1][j-1]){
            ret=max(ret,arr[i][j]=min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1]))+1);
        }
    }
    cout<<ret*ret<<'\n';
}