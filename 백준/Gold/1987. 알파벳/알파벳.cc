#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int d[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
string b[20];
int r,c; 

int ret[20][20] ={0,};
int alpa[128]={0,};

int ret_max=0;

bool isOK(int y, int x){
    return 0<=y && y<r && 0<=x && x<c;
}

void Find(int y,int x){  
    for(int i=0;i<4;i++){
        int n_y=y+d[i][0],n_x=x+d[i][1];
        if(!isOK(n_y,n_x) || alpa[b[n_y][n_x]]) continue; // 범위를 넘었거나 이미 방문한 알파벳이면 패쓰
        
        ret[n_y][n_x]=ret[y][x]+1;
        alpa[b[n_y][n_x]]++;
        ret_max = max(ret[n_y][n_x],ret_max); // 최댓값 갱신 

        Find(n_y,n_x);

        alpa[b[n_y][n_x]]--;
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>r>>c;
    for(int i=0;i<r;i++)cin>>b[i];

    alpa[b[0][0]]++;
    ret_max=1;
    ret[0][0]=1;
    Find(0,0);
    cout<<ret_max<<'\n';
}