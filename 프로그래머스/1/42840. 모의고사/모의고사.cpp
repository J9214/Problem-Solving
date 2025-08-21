#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int arr1[5] = {1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    int a=0,b=0,c=0;
    for(int i = 0 ; i < answers.size() ; i++){
        if(answers[i] == arr1[i%5]) a++;
        if(answers[i] == arr2[i%8]) b++;
        if(answers[i] == arr3[i%10]) c++;
    }
    
    vector<int> answer;
    int m_ = max({a,b,c});
    if(a==m_) answer.push_back(1);
    if(b==m_) answer.push_back(2);
    if(c==m_) answer.push_back(3);
    
    
    return answer;
}