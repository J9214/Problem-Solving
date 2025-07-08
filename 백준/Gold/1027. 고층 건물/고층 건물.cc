#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

double rad(vector<double> vec, double a, double b){
    return ((vec[a] - vec[b]) / abs((a - b)));
}

int main() {
    FASTIO
 
    int n; cin >> n;
    vector<double> vec(n);
    for(int i = 0 ; i < n; i++)
        cin >> vec[i];
    
    int maxcnt = 0;
    for(int i = 0 ; i < n; i++){
        int cnt = 0;
        double r = INT_MIN;
        int j = i - 1;
        while(j >= 0){
            if(rad(vec,j,i) > r) {
                r = rad(vec,j,i);
                cnt++;
            }
            j--;
        }
        r = INT_MIN;
        j = i + 1;
        while(j < vec.size()){
            if(rad(vec,j,i) > r) {
                r = rad(vec,j,i);
                cnt++;
            }
            j++;
        }
        maxcnt = max(cnt, maxcnt);
    }
    cout << maxcnt;
    return 0;
}
