#include<iostream>
using namespace std;
int main(){
    int s,n; cin>>s>>n;
    while(n--){
        int a,b; cin>>a>>b;
        s-=a*b;
    }
    if(!s)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}