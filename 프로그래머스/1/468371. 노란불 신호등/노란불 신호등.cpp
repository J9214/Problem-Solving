#include <string>
#include <vector>
#include <math.h>
#define SIZE 5000000
using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = 0;
    vector<int> vec(SIZE,0);
    for(int i = 0 ; i < signals.size() ; i++){
        for(int j = 0 ; j < SIZE;){
            for(int k = 0; k < signals[i][0] && j<SIZE; k++,j++) vec[j]+=pow(5,0);
            for(int k = 0; k < signals[i][1] && j<SIZE; k++,j++) vec[j]+=pow(5,1);
            for(int k = 0; k < signals[i][2] && j<SIZE; k++,j++) vec[j]+=pow(5,2);
        }
    }
    
    for(int i = 0 ; i < vec.size(); i++){
        if(vec[i] == 5*signals.size()) return i+1;
    }
    return -1;
}