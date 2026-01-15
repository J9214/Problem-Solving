#include<iostream>
#include<algorithm>
#define SIZE 2000
using namespace std;

int arr[SIZE];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);

    int ret=0;
    for(int i=0;i<n;i++){
        int l=0,r=n-1,goal=arr[i];
        
        while(l<r){
            // "다른" 수 두 개의 합이여야 함 
            if(l==i){l++; continue;}
            if(r==i){r--; continue;}

            int cur = arr[l]+arr[r];
            if(cur==goal){
                ret++;
                break;
            }
            else if(cur<goal) l++;
            else r--;
        }
    }
    cout<<ret<<'\n';
}