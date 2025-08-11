#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool b=1;
    string answer = "";
    for(auto &x : s){
        if(x==' ' || x == '-') b=1;
        else {
            if(b) x=toupper(x);
            else x= tolower(x);
            b=!b;
        }
    }
    return s;
}