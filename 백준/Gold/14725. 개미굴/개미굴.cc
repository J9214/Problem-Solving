#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define SIZE 1000
using namespace std;

vector<vector<string>> vec;

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);

    int n; cin>>n;
    string str;
    for(int i=0,cnt;i<n;i++){
        cin>>cnt;

        vector<string> t;
        while(cnt--){
            cin>>str;
            t.push_back(str);
        }
        vec.push_back(t);
    }

    sort(&vec[0],&vec[0]+n);

    vector<string> v;

    for(int i=0;i<n;i++){
        for(int j=0;j<vec[i].size();j++){
            if(j>=v.size()) v.push_back(vec[i][j]);
            else if(vec[i][j] == v[j]) continue;
            else {
                while(v.size()>j)v.pop_back();
                v.push_back(vec[i][j]);
            }

            int tmp=j;
            while(tmp--) cout<<"--";
            cout<<v[j]<<'\n';
        }
    }
}