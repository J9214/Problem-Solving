#include<iostream>
#include<queue>
#include<algorithm>
#define SIZE 100'001
using namespace std;

struct info
{
    int s,e;

    bool operator<(const info&a) const {
        if(s==a.s) return s<a.e;
        return s<a.s;
    }
};

info arr[SIZE];
priority_queue<int,vector<int>,greater<int>> pq; // 사용중인 회의실

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].s>>arr[i].e;
    sort(arr,arr+n);

    pq.push(0);

    for(int i=0;i<n;i++){
        info cur = arr[i];
        if(pq.top()<=cur.s) pq.pop();
        pq.push(cur.e);
    }

    cout<<pq.size()<<'\n';
}