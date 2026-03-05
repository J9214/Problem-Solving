#include<iostream>
#include<vector>
#include<algorithm>
#define SIZE 11
using namespace std;

struct info{int s,n;}; // 실력, 몇번 선수? 
bool cmp(const info& a, const info& b){return a.s>b.s;};

vector<vector<info>> graph(SIZE); // 포지션별 

int ret=0;
// v : 몇번 선수를 썼는지
// pos: 몇번째 포지션을 결정중인지
void DFS(int pos, int sum, int v){ 
    // base
    if(pos==11){
        ret=max(ret,sum);
        return;
    }

    // recursive
    for(int i=0;i<graph[pos].size();i++){
        info cur = graph[pos][i];
        if((v>>cur.n)&1) continue; 
        DFS(pos+1,sum+cur.s,v|(1<<cur.n));
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // 각 테케에 대하여
    int c; cin>>c;
    while(c--){
        // graph 초기화
        for(int i=0;i<SIZE;i++)graph[i].clear();
        
        // 정보 입력받기 
        int a;
        for(int i=0;i<SIZE;i++)for(int j=0;j<SIZE;j++){
            cin>>a;
            if(a) graph[j].push_back({a,i});
        }

        // 각 포지션별 실력 내림차순
        for(int i=0;i<SIZE;i++) sort(graph[i].begin(),graph[i].end(),cmp);
        
        ret=0; // 결과 초기화
        DFS(0,0,0);
        cout<<ret<<'\n';
    }
}