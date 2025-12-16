#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    long long n,k=1,ret=0; 
    cin>>n;
    for(int i=0;i<40;i++){
        long long tmp = n>>i;
        if(i) k*=3;
        if(tmp&1) ret+=k;
    }
    cout<<ret<<'\n';
}