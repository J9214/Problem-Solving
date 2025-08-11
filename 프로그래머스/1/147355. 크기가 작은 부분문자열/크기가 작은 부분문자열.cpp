#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int s = p.size();
    for(int i = 0 ; i < t.size()-s+1 ; i++)
        if(t.substr(i,s) <= p) answer++;
    return answer;
}