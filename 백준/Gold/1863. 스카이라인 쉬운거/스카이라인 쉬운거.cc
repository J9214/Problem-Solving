#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
    FASTIO
    int n; cin >> n;
    priority_queue<int> pq;
    int res =0 ;
    while(n--){
        int a,b;cin >>a >> b;
        while(!pq.empty()&&pq.top() > b) res++,pq.pop();
        if(b&&(pq.empty()||pq.top() != b)) pq.push(b);
    }
    cout << res+pq.size();
}