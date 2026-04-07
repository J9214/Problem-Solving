#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define SIZE 50'001
using namespace std;

vector<vector<pair<int,int>>> graph(SIZE);
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 코스트, 노드


int arr[SIZE];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // 입력받기
    int n,m; cin>>n>>m;
    for(int i=0,a,b,c;i<m;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    // 초기화
    for(int i=1;i<=n;i++) arr[i]=INT_MAX;
    arr[1]=0;

    pq.push({0,1});
    while(pq.size()){
        int cur_node = pq.top().second;
        int cur_cost = pq.top().first; 
        pq.pop();

        if (cur_cost > arr[cur_node]) continue;
        
        for(int i=0;i<graph[cur_node].size();i++){
            int n_node = graph[cur_node][i].first;
            int c = graph[cur_node][i].second;

            if(arr[n_node] > cur_cost+c){
                arr[n_node] = cur_cost+c;
                pq.push({arr[n_node],n_node});
            }
        }
    }

    cout<<arr[n]<<'\n';
}