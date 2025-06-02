#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, data, sum = 0, bin = 0;
    vector<int> vec;
    vector<int> binvec;
    int *arr = new int[8001]{0};

    cin >> n;

    while(n --> 0){
        cin >> data;
        sum += data;
        vec.push_back(data);
        arr[data + 4000]++;
    }

    for(int i = 0; i < 8002; i++){
        if(arr[i] < bin) continue;
        if(arr[i] > bin) {
            bin = arr[i];
            binvec.clear();
        }
        binvec.push_back(i - 4000);
    }
    sort(vec.begin(), vec.end());

    abs(round((float)sum / vec.size())) < 1 ? cout << 0 << '\n' : cout << round((float)sum / vec.size()) << '\n';
    cout << vec[vec.size() / 2] << '\n';
    if(binvec.size() > 1) cout << binvec[1] <<'\n';
    else cout << binvec[0] << '\n';
    cout << vec[vec.size() - 1] - vec[0];
}