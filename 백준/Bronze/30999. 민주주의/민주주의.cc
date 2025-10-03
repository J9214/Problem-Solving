#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,m,ret=0; cin>>n>>m;
    for(int i=1;i<=n;i++){
        string str; cin>>str;
        int cnt=0;
        for(int j=0;j<m;j++) if(str[j]=='O')cnt++;
        if(cnt>=(m/2+1))ret++;
        
    }
    cout<<ret<<endl;
}