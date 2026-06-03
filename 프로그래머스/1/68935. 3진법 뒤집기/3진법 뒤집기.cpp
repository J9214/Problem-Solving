#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s ="";
        
    while(n){
        s+=n%3+'0';
        n/=3;
    }

    int res = 0;
    for(int i = 0 ; i < s.size(); i++){
        res += (s[i]-'0') * pow(3,s.size()-i-1);
    }
    return res;
}