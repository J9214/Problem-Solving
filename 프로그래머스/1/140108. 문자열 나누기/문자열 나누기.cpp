#include <string>
#include <vector>

using namespace std;

int solution(string str) {
    int answer = 0;
    char c = 0;
    int s= 0, d= 0;
    for(auto i : str){
        if(c==0)
            c=i,s=d=0;
        if(c==i) s++;
        else d++;
        if(s==d) answer++, s=d=c=0;
    }
    if(c!=0) answer++;
    
    return answer;
}