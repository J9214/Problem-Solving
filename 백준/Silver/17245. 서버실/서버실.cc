#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long long> v;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    long long n; cin>>n;
    
    long long s=0;
    
    for(long long i=0,tmp;i<n*n;i++){
        cin>>tmp;
        if(!tmp) continue;
        v.push_back(tmp);
        s+=tmp;
    }
    sort(v.begin(),v.end());

    long long ret=0,cur=0,idx=0;
    while(cur*2<s){
        cur += v.size()-idx;
        ret++;
        auto it = upper_bound(v.begin(),v.end(),ret);
        idx = it-v.begin();
    }
    cout<<ret<<'\n';
}