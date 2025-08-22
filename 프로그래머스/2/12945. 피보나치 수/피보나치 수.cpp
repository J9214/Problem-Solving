#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> vec = {0,1,1};
    for(int i= 3; i <= n ; i++)
        vec[i%3] = (vec[(i+1)%3] +vec[(i+2)%3])%1234567;
    
    return vec[n%3];
}