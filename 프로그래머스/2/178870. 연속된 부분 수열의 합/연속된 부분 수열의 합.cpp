#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<int> vec = {0};
    for(int i = 0 ; i < sequence.size(); i++){
        vec.push_back(vec.back()+sequence[i]);
    }
    
    for(int i=1,j=1; i<vec.size()&&j<vec.size();){
        if(vec[j]-vec[i-1]==k){
            if(answer.empty() || answer[1]-answer[0] > j-i){
                answer = {i-1,j-1};
            }
        }
        
        if(i==j || vec[j]-vec[i-1] <= k) j++;
        else i++;
    }

    return answer;
}