#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    int i=0,j=0;
    vector<int> vec(10,0);
    while(i<X.size()&&j<Y.size()){
        if(X[i]==Y[j]) {
            vec[X[i]-'0']++;
            i++;
            j++;
        }
        else if(X[i] < Y[j]) i++;
        else j++;        
    }
    for(int i = 9; i>=0; i--)
        answer.append(vec[i], (char)(i+'0'));
    
    if(answer.empty()) answer = "-1";
    else if(answer[0]=='0') answer = "0";
    
    return answer;
}