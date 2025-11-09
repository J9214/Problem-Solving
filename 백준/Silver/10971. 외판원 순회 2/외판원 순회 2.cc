#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// 모든 경우의 수 구해서 최솟값 
// 10 펙토리얼 == 3'628'800

int cost[10][10];
int main(){
    // 입력 받기 
    int n; cin>>n; //10
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>cost[i][j];
    
    vector<int> v;
    for(int i=0;i<n;i++)v.push_back(i);

    int ret=INT_MAX;
    do{
        int sum=0;
        int able = 1;
        for(int i=0;i<n;i++){
            int c = i==n-1?cost[v[n-1]][v[0]] : cost[v[i]][v[i+1]];
            if(c==0){able = 0; break;} // 갈 수 없는 경우 
            sum+=c;
        }
        if(!able) continue;
        ret=min(ret,sum);
    }
    while(next_permutation(v.begin(),v.end()));
    cout<<ret<<'\n';

}