#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;
    for(int i = 2; i <=number; i++){
        int t = 0;
        for(int j = 1; (long long)j * j <= i; j ++)
            if(!(i%j))
                if(j*j == i) t++;
                else t+=2;
        if(t>limit) answer+=power;
        else answer+=t;
    }
    return answer;
}