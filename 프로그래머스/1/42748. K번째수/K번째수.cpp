#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0 ; i < commands.size() ; i++){
        vector<int> vec;
        for(int j = commands[i][0]-1 ; j <= commands[i][1]-1; j++)
            vec.push_back(array[j]);
        sort(vec.begin(),vec.end());
        answer.push_back(vec[commands[i][2]-1]);
    }
    return answer;
}