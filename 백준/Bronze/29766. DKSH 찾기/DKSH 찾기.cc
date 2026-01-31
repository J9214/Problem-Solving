#include<iostream>
#include<string>
using namespace std;
int main(){
 
    string str; cin >> str;
    int res=0;
    for(int i = 0 ; i < str.size()-3; i++){
        if(str[i]=='D'&&str[i+1]=='K'&&str[i+2]=='S'&&str[i+3]=='H') res++;
    }
    cout <<res;
}