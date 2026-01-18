#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point { int x, y; } point;

int main(){
    FASTIO
    vi vec(8);
    vi permute = {0,1,2,3,4,5,6,7};
    int res = 40320;

    for(auto &i : vec) cin >> i;
    sort(vec.begin(), vec.end());

    do{
        for(int i = 0; i < 8; i++){
            double x = vec[permute[i]];
            double y = vec[permute[(i+1)%8]];
            double z = vec[permute[(i+2)%8]];

            double l = 1.41421356;

            if(y * (x + z) <= l * x * z){
                res--;
                break;
            }
        }
    } while(next_permutation(permute.begin(), permute.end()));

    cout << res;
}
