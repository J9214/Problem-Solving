#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    string s = to_string(n);
    for(int i = 0 ; i  < s.size() ; i++){
        for(int j = 0; j < s.size(); j++){
            if(s[j] < s[i]) swap(s[i],s[j]);
        }
    }
    return stoll(s);
}