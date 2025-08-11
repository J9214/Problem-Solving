#include <string>
#include <vector>

using namespace std;

int res =0;
void recur(vector<int> &vec, int n, int idx, int d){
    if(d==2) {
        if(n==0) res++;
        return;
    };
    for(int i = idx+1; i<vec.size(); i++)
        recur(vec,n+vec[i],i,d+1);
    
}
int solution(vector<int> number) {
    int answer = 0;
    for(int i = 0 ; i<number.size()-2; i++)
        recur(number,number[i],i,0);
    answer=res;
    return answer;
}