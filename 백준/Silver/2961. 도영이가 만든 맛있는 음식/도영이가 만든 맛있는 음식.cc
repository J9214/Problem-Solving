#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Info{int s,b;};

vector<Info> list;
int n;
int ret= INT_MAX;

void Solution(int d,int t_s, int t_b){
    if(t_b) ret=min(abs(t_s-t_b),ret);
    
    //base
    if(d==n) return;

    //recursive
    Solution(d+1,t_s*list[d].s,t_b+list[d].b);// 넣는 경우
    Solution(d+1,t_s,t_b); // 안넣는 경우
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        list.push_back({a,b});
    }
    Solution(0,1,0);
    cout<<ret<<'\n';
}