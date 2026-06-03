#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<pair<int,int>> direct = {{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<pair<int,int>>> contain(26);

void lift(vector<vector<char>> &board, char c){
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(),0));
    queue<pair<int,int>> q;
    queue<pair<int,int>> out;
    q.push({0,0});
    visited[0][0] = 1;

    while(q.size()){
        auto [x,y] = q.front(); q.pop();
        
        for(auto dir : direct){
            int nx = x+dir.first;
            int ny = y+dir.second;
            if(nx<0||ny<0||nx>=board.size()||ny>=board[0].size()||visited[nx][ny]) continue;
            if(board[nx][ny] == 0) q.push({nx,ny}); 
            if(board[nx][ny] == c) out.push({nx,ny});
            visited[nx][ny]=1;
        }
    }
    
    while(out.size()){
        board[out.front().first][out.front().second] = 0;
        out.pop();
    }
}
void crane(vector<vector<char>> &board, char c){
    for(auto i:contain[c-'A']){
        board[i.first][i.second] = 0;
    }
    contain[c].clear();
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    vector<vector<char>> board(storage.size()+2, vector<char>(storage[0].size()+2,0));
    
    for(int i = 0 ; i < storage.size(); i++){
        for(int j = 0 ; j < storage[i].size();j++){
            board[i+1][j+1] = storage[i][j];
            contain[storage[i][j]-'A'].push_back({i+1,j+1});
        }
    }
    
    for(auto i : requests){
        if(i.size()==1)lift(board, i[0]);
        else crane(board,i[0]);
    }
    
    for(auto i:board) for(auto j:i) if(j!=0) answer++;
    
    return answer;
}
