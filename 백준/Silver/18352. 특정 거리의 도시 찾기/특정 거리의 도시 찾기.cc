#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    vector<vector<int>> v(300001);
    vector<int> dist(300001,INT_MAX);

    // freopen("input.txt","r",stdin);
    int n,m,k,x,s,e; cin>>n>>m>>k>>x;
    while(m--){
        cin>>s>>e;
        v[s].push_back(e);
    }
    vector<int> ret;
    queue<int> q; // 노드
    q.push(x);
    dist[x]=0;
    
    while(q.size()){
        int cur = q.front(); 
        int d = dist[cur];
        q.pop();
        
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(dist[next]>d+1){
                q.push(next);
                dist[next]=d+1;
            }
        }
    }

    bool is = false;
    for(int i=1;i<=n;i++){
        if(dist[i]==k){
            cout<<i<<'\n';
            is = 1;
        }
    }
    if(is)exit(0);
    cout<<-1<<endl;

}
