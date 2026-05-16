#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int res = 9999999;
vector<int> memo;
void recur(vector<vector<int>> &info, int n, int m, int idx, int a, int b){
    if(a>=n || b>=m || a >= memo[idx]) return;
    if(idx == info.size()) {
        res = min(res, a);
        return;
    }
    
    memo[idx] = min(memo[idx], a);
    recur(info,n,m,idx+1, a+info[idx][0],b);
    recur(info,n,m,idx+1, a,b+info[idx][1]);
}
int solution(vector<vector<int>> info, int n, int m) {
    memo.assign(info.size(), 9999999);
    recur(info,n,m,0,0,0);
    if(res>=n) return -1;
    return res;
}