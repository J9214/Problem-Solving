#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,a=0,b=0;
    string str; cin>>n>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='A')a++;
        else b++;
    }
    if(a>b) cout<<"A"<<endl;
    else if(a<b) cout<<"B"<<endl;
    else cout<<"Tie"<<endl;
}