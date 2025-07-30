#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    double x,y,m,n; cin>>x>>y>>n;
    m=x/y;
    while(n--){
        cin>>x>>y;
        double tmpM = x/y;
        m=min(m,tmpM);
    }
    cout<<fixed;
    cout.precision(2);
    cout << m*1000 << '\n';
    
    
    
}