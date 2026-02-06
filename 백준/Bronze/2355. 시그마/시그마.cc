#include<iostream>
using namespace std;
int main(){
    long long a,b,ret=0; cin>>a>>b;
    if(a==b){
        cout<<a<<'\n';
        exit(0);
    }
    if(a>b){
        long long tmp = a;
        a=b;
        b=tmp;
    }
    // 전체 홀수
    if((b-a+1)%2){
        ret = (a+b)*((b-a+1)/2)+ (a+b)/2;
    }
    // 전체 짝수
    else{
        ret = (a+b)*(b-a+1)/2;
    }
    cout<<ret<<'\n';
}