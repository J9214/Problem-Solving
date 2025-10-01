#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int i = 0, t=0;
    int n = 0;
    while(i < speeds.size()){
        n++;
        while(i < speeds.size() && progresses[i] + speeds[i] * n >= 100){
            i++,t++;
        }
        if(t) answer.push_back(t);
        t=0;
    }
    return answer;
}