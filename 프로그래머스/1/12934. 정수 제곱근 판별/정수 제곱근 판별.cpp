#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long t = floor(sqrt(n));
    return (sqrt(n)-t?-1:(t+1)*(t+1));
}