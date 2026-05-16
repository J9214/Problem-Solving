#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int res = 9999999;
struct st{
    int a,b,c;
    bool operator<(const st &other) const{
        if(a==other.a){
            if(b==other.b) return c<other.c;
            return b<other.b;
        }
        return a<other.a;
    }
};
set<st> s;
void recur(vector<vector<int>> &info, int n, int m, int idx, int a, int b){
    if(a>=n || b>=m) return;
    if(idx == info.size()) {
        res = min(res, a);
        return;
    }
    if(s.find({idx,a,b})!=s.end()) return;

    s.insert({idx,a,b});
    
    recur(info,n,m,idx+1, a+info[idx][0],b);
    recur(info,n,m,idx+1, a,b+info[idx][1]);
}
int solution(vector<vector<int>> info, int n, int m) {
    recur(info,n,m,0,0,0);
    if(res>=n) return -1;
    return res;
}