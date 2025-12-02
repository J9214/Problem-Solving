#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Info{int s,b;};

vector<Info> list;
int n;
int ret= INT_MAX;

void Solution(int v, int d){
    //base
    if(d>=n){
        if(!v) return; // 하나도 안넣었으면 패쓰
        int total_s=1,total_b=0;
        for(int i=0;i<n;i++){
            if((v>>i)&1){
                total_s *=list[i].s;
                total_b +=list[i].b;
            }
        }
        ret=min(abs(total_s-total_b),ret);
        return;
    }

    //recursive
    Solution(v|(1<<d),d+1);// 넣는 경우
    Solution(v,d+1); // 안넣는 경우
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>n;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        list.push_back({a,b});
    }
    Solution(0,0);
    cout<<ret<<'\n';
}