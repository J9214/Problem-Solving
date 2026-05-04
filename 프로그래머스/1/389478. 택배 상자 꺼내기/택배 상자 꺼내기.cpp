#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int row = (num-1)/w;
    int col = (num-1)%w;
    col = (row%2?w-1-col:col);
    
    int trow = (n-1)/w+1;
    int count = n-(trow-1)*w;
    
    answer = trow-row;
    if((trow-1)%2) answer -= (w-count>col);
    else answer -= (count<=col);
    
    return answer;
}