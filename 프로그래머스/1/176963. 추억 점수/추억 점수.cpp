#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> mp;
    for(int i = 0 ; i < name.size(); i++)
        mp[name[i]]=yearning[i];
    
    for(auto &p : photo){
        int score=0;
        for(auto &i : p){
            score += mp[i];
        }
        answer.push_back(score);
    }
    
    return answer;
}