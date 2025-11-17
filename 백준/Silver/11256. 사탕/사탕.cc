#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    priority_queue<int> pq;
    while(t--){
        pq = priority_queue<int>(); // 초기화
        int t,b; cin>>t>>b;
        while(b--){
            int a,b; cin>>a>>b;
            pq.push(a*b);
        }

        int ret=0;
        while(t>0){
            t-=pq.top();
            pq.pop();
            ret++;
        }

        cout<<ret<<'\n';
    }
}