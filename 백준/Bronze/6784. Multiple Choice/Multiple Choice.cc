#include<iostream>
using namespace std;
int main(){
    char list[10000];
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>list[i];
    
    int ret=0;
    for(int i=0;i<n;i++){
        char tmp; cin>>tmp;
        if(list[i]==tmp)ret++;
    }
    cout<<ret<<endl;
    
    
}