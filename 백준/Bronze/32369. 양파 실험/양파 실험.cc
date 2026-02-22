#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie();
	int a,b,n; cin>>n>>a>>b;
	int c=1,d=1;
	while(n--){
		c+=a;d+=b; 
		if(c<d){
			int tmp=c;
			c=d; d=tmp;
		}

		if(c==d)d--;
	}
	cout<<c<<' '<<d<<endl;
}