#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    deque<int> dq;
    int n,tmp; cin>>n;
    while(n--){cin>>tmp; dq.push_back(tmp);}
    sort(dq.begin(),dq.end(),greater<int>());

    int ret=0;
    while(dq.size()){
        int cur = dq.front(); dq.pop_front();
        ret++;
        if(cur==4) continue; 
        else if(cur==3){
            if(dq.size() && dq.back()==1) dq.pop_back();
        }
        else if(cur==2){
            if(dq.size()){
                if(dq.back()==2)dq.pop_back();
                else if(dq.back()==1){
                    dq.pop_back();
                    if(dq.back()==1)dq.pop_back();
                }
            }
        }
        else if(cur==1){
            int cnt=0;
            while(dq.size()&& cnt<3){
                dq.pop_back();
                cnt++;
            }
        }
        continue;
    }
    cout<<ret<<'\n';
}