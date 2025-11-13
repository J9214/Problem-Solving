#include<iostream>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string str[50];
    // freopen("input.txt","r",stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++)cin>>str[i];
    int ret=0;
    for(int i=0;i<n;i++){
        int v[50]={0,};
        int cur=0;
        for(int j=0;j<n;j++){
            // 직속 친구
            if(str[i][j]=='Y' && !v[j]){v[j]=1; cur++; }  

            // 한다리 건너 친구 
            if(str[j][i]=='Y'){
                for(int k=0;k<n;k++){
                    if(k==i) continue;
                    if(str[j][k]=='Y' && !v[k]){ v[k]=1; cur++;}
                }
            }
        }
        ret=max(ret,cur);
    }
    cout<<ret<<'\n';
}