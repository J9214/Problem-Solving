#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    set<string> noSp, Sp; // 노스포, 스포
    
    bool spoiler=false;
    bool current_Spoiler=false;
    string str;
    int spoiler_idx=0;
    for(int i = 0 ; i < message.size(); i++){
        if(message[i] == ' '){
            if(current_Spoiler) Sp.insert(str);
            else noSp.insert(str);
            current_Spoiler = false;
            str = "";
        }
        else {
            if(spoiler_idx < spoiler_ranges.size()){
                if(i>spoiler_ranges[spoiler_idx][1]) spoiler_idx++;
                if(spoiler_idx < spoiler_ranges.size() && spoiler_ranges[spoiler_idx][0] <= i && i <= spoiler_ranges[spoiler_idx][1]) spoiler=true;
                else spoiler=false;
                if(spoiler) current_Spoiler=true;
            }

            if(message[i] != ' ') {
                str += message[i];
            }
        }
        
        
    }
    if(current_Spoiler) Sp.insert(str);
    else noSp.insert(str);

    for(auto &i :Sp){
        answer += (noSp.find(i) == noSp.end());
    }
    
    return answer;
}