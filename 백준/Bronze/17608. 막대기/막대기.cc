#include<iostream>
#include<stack>
using namespace std;

stack<int> st;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;

    for(int i=0,tmp;i<n;i++){
        cin>>tmp;
        st.push(tmp);
    }

    int ret=0,cur=0;
    while(st.size()){
        int next = st.top(); st.pop();
        if(next>cur){
            ret++;
            cur=next;
        }
    }
    cout<<ret<<'\n';
}