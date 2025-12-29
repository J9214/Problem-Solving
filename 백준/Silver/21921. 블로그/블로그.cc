#include<iostream>
#include<algorithm>
#define SIZE 250'000
using namespace std;

long long list[SIZE]={0,};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,x; cin>>n>>x;
    long long tmp,ret=0,cnt=0;
    for(int i=1,tmp;i<=n;i++){
        cin>>tmp;
        list[i]=list[i-1]+tmp;
        
        if(i>=x){
            tmp = list[i]-list[i-x];
            if(tmp>ret){
                ret=tmp;
                cnt=1;
            }
            else if(tmp==ret) cnt++;
        }
    }
    if(ret) cout<<ret<<'\n'<<cnt<<'\n';
    else cout<<"SAD"<<'\n';
}