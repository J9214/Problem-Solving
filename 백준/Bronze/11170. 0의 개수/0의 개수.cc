#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m,ret=0; cin>>n>>m;
        for(int i=n;i<=m;i++){
            int tmp=i;
            while(1){
                if(tmp%10==0) ret++;
                tmp/=10;
                if(tmp==0) break;
            }
        }
        cout<<ret<<'\n';
    }
}