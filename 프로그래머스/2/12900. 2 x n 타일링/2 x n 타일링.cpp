#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> vec(n);
    vec[0] = 1;
    vec[1] = 2;
    
    for(int i = 2 ; i < n ; i++) vec[i] = (vec[i-1] + vec[i-2])%1000000007;
    
    return vec[n-1];
}