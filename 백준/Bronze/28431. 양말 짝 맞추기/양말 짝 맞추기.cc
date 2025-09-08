#include<iostream>
using namespace std;
int main(){
    int list[10]={0,};
    int n=5,tmp;
    while(n--){
        cin>>tmp; list[tmp]++;
    }
    for(int i=0;i<10;i++){
        if(list[i]%2==1){
            cout<<i<<endl;
            exit(0);
        }
    }
}