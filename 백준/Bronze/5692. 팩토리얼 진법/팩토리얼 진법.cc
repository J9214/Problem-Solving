#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;
    while(n){
        int i=1,p=1,ret=0;
        while(n){
            p*=i;
            ret+=(n%10)*p;
            n/=10;
            i++;
        }
        cout<<ret<<'\n';
        cin>>n;
    }
}