#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string s = "";
    for(int i = 1; i < food.size(); i++)
        for(int j = 0 ; j < food[i]/2; j ++)
            s+=to_string(i);
    s+='0';
    for(int i = food.size()-1; i > 0; i--)
        for(int j = 0 ; j < food[i]/2; j ++)
            s+=to_string(i);
    return s;
}