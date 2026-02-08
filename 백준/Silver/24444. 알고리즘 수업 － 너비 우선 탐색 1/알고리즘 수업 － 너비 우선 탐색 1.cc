#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define SIZE 100'001
using namespace std;
vector<vector<int>> graph(SIZE);
int v[SIZE]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // 입력 받기 
    int n,m,r; cin>>n>>m>>r;
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 정점 번호를 오름차순으로 방문
    for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());

    // BFS
    int cnt=1;
    queue<int> q;
    q.push(r);
    v[r]=cnt++;
    while(q.size()){
        int cur = q.front(); q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(v[next]) continue;
            v[next]=cnt++;
            q.push(next);
        }
    }
    for(int i=1;i<=n;i++) cout<<v[i]<<'\n';
}