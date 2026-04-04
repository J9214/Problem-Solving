#include<iostream>
#include<map>
using namespace  std;

map<long long,long long> m;
long long n,p,q;

long long Solve(long long n){
    // base
    if(!n) return 1;

    // recursive
    if(m[n]) return m[n];
    return m[n] = Solve(n/p) + Solve(n/q);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>p>>q;
    cout<<Solve(n)<<'\n';
}
