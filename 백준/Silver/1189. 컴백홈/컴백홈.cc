#include<iostream>
using namespace std;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char m[5][5];
int visit[5][5];
int a,b,c;

bool isOK(int y,int x){
    return 0<=y && y<a && 0<=x && x<b && m[y][x]!='T';
}

int ret=0;
void DFS(int y, int x, int depth){
    //base
    if(depth>=c){
        if(y==0 && x==b-1) ret++;
        return;
    }
    // recursive
    for(int i=0;i<4;i++){
        int ny = y+dir[i][0];
        int nx = x+dir[i][1];

        if(!isOK(ny,nx) || visit[ny][nx]) continue;
        visit[ny][nx]=1;
        DFS(ny,nx,depth+1);
        visit[ny][nx]=0;
    }
    
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b>>c;
    for(int i=0;i<a;i++)cin>>m[i];
    visit[a-1][0]=1;
    DFS(a-1,0,1);
    cout<<ret<<'\n';

}