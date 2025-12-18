#include<iostream>
using namespace std;
int main(){
    int ret=0,tmp,a,b;
    for(int i=0;i<9;i++)for(int j=0;j<9;j++){
        cin>>tmp;
        if(tmp>=ret){
            ret=tmp;
            a=i;b=j;
        }
    }
    cout<<ret<<endl<<a+1<<' '<<b+1<<endl;
}