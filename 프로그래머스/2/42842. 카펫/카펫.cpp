#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int t = brown + yellow;
    for(int i = 3; i * i <= t; i++){
        if(!(t%i)){
            if((t/i-2)*(i-2)==yellow) return {t/i,i};
        }
    }
}