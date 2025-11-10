//  17세보다 많거나, 몸무게가 80kg 이상이면 성인부
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str; int a,b;
    while(1){
        cin>>str>>a>>b;
        if(str == "#" && !a && !b) break;
        cout<<str<<' ';
        if(a>17 || b>=80) cout<<"Senior"<<'\n';
            else cout<<"Junior"<<'\n';
    }
}