#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(auto &x : arr){
        if(!(x%divisor)) answer.push_back(x); 
    }
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1); 
    return answer;
}