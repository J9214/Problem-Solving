#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n = 5;
    bool is = 0;
    for(int i=0;i<n;i++){
        string str; cin>>str;
        for(int j=0; j<str.size()-2;j++){
            if(str[j]=='F' && str[j+1]=='B' && str[j+2]=='I'){
                cout<<i+1<<' ';
                is = 1;
                break;
            }
        }
    }
    if(!is)cout<<"HE GOT AWAY!"<<'\n';
}