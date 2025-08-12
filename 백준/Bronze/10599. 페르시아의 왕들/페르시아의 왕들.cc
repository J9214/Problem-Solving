#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while(a || b || c || d){
        cout<<c-b<<' '<<d-a<<'\n';
        cin>>a>>b>>c>>d;
    }
}