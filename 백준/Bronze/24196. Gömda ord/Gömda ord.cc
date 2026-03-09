#include<iostream>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string str,ret="";cin>>str;

    for(int i=0;i<str.size();){
        ret+=str[i];
        i+=(str[i]-'A'+1);
    }
    cout<<ret<<'\n';
}