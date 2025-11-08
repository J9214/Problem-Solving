#include<iostream>
#include<string>
using namespace std;

int CtoI(char c){
    if(c=='A')return 0;
    else if(c=='G')return 1;
    else if(c=='C')return 2;
    else if(c=='T')return 3;
}

char m[4][4]={
    {'A','C','A','G'},
    {'C','G','T','A'},
    {'A','T','C','G'},
    {'G','A','G','T'}};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;
    string str; cin>>str;
    while(str.size()>1){
        str[str.size()-2] = m[CtoI(str[str.size()-2])][CtoI(str[str.size()-1])];
        str.pop_back();
    }
    cout<<str<<'\n';
}