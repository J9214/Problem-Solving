#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 100000;
    map<int, int> mp;
    for(auto i : tangerine) mp[i]++;
    sort(tangerine.begin(), tangerine.end(), [&](int a, int b){
        if(mp[a] == mp[b]) return a>b;
        return mp[a] > mp[b];
    });

    int j=0, r = 1;
    if(k==1) return 1;
    for(int i = 1;  i < tangerine.size(); i++){
        if(tangerine[i] != tangerine[i-1]) r++;
        if(i-j==k-1)answer = min(r,answer);
        if(i-j>=k){
            if(tangerine[j+1] != tangerine[j]) r--;
            j++;
        }
    }
    return answer;
}