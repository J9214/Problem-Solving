#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    int list[5]={0,};
    for(int i=0;i<t;i++) cin>>list[i];
    
    int ret=0; 
    if(list[0]>list[2]) ret+=(list[0]-list[2])*508;
    else ret+= (list[2]-list[0])*108;
    
    if(list[1]>list[3]) ret+=(list[1]-list[3])*212;
    else ret+=(list[3]-list[1])*305;
    
    if(list[4]>0) ret+=list[4]*707;
    cout<<ret*4763<<endl;
    
}