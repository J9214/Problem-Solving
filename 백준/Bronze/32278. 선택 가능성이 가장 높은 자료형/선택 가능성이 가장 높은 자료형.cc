#include<iostream>
#include<climits>
using namespace std;
int main(){
    
    long long n; cin>>n;
    if(-32768<=n && n<=32767)cout<<"short"<<endl;
    else if(INT_MIN<=n && n<=INT_MAX) cout<<"int"<<endl;
    else cout<<"long long"<<endl;       
}