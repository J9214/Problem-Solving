#include<iostream>
#include<map>
using namespace  std;

map<long long,long long> m;
long long n,p,q;

long long Solve(long long n){
    // base
    if(n==0) return 1;

    // recursive
    long long ret;
    if(m[n]) ret = m[n];
    else{
        ret = Solve(n/p) + Solve(n/q);
        m[n] = ret;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>p>>q;
    cout<<Solve(n)<<'\n';
}
