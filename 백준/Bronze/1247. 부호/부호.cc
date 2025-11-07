#include<iostream>
using namespace std;
int main(){
    int t=3;
    while(t--){
        long long tmp;
        __int128 sum=0;
        int n; cin>>n;
        while(n--){
            cin>>tmp;
            sum+=(__int128)tmp;
        }
        if(sum>0)cout<<"+"<<'\n';
        else if(sum<0)cout<<'-'<<'\n';
        else cout<<0<<'\n';

    }

}