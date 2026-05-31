#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
#define MAX 99999999

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer;

    vector<vector<int>> arr(m+1,vector<int>(n+1,MAX));
    
    map<int,int> mp;
    
    for(int i = 0; i < drops.size() ; i++){
        arr[drops[i][0]][drops[i][1]] = i+1;
    }   

    vector<vector<int>> row(m,vector<int>(n-w+1,MAX));

    for(int i = 0 ; i < m ; i++){
        mp.clear();
        for(int j = 0 ; j < n; j++){
            mp[arr[i][j]]++;

            if(j>=w){
                mp[arr[i][j-w]]--;
                if(mp[arr[i][j-w]]==0) mp.erase(arr[i][j-w]);
            }

            if(j>=w-1) {
                row[i][j-w+1] = mp.begin()->first;
            }
        }
    }  
            
    vector<vector<int>> rect(m-h+1,vector<int>(n-w+1,MAX));
    
    for(int i = 0 ; i < n-w+1 ; i++){
        mp.clear();
        for(int j = 0 ; j < m; j++){
            mp[row[j][i]]++;
            
            if(j>=h){
                mp[row[j-h][i]]--;
                if(mp[row[j-h][i]]==0) mp.erase(row[j-h][i]);
            }

            if(j>=h-1) {
                rect[j-h+1][i] = mp.begin()->first;
            }    
        }
    }

    int cnt = 0;
    
    for(int i = 0 ; i < rect.size(); i++){
        for(int j = 0 ; j < rect[0].size(); j++){
            if(rect[i][j] == MAX) return {i,j};
            if(rect[i][j] > cnt) {
                answer = {i,j};
                cnt = rect[i][j];
            }
        }
    }
    
    return answer;
}