#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,cnt=1;
    while(cin>>n && n){
        for(int i=0,tmp;i<n;i++) cin>>tmp;
        cout<<"Case "<<cnt++<<": Sorting... done!"<<'\n';
    }

}