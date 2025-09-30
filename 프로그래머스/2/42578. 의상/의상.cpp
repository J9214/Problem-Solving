#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> mp;
    for(auto i : clothes) mp[i[1]]++;
    int ret=1;
    for(auto m : mp) ret *= m.second+1;
    return ret-1;
}