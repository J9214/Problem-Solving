#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int a,b,c,s; cin>>a>>b>>c>>s;

    // 1
    int tmp = s;
    if(tmp%a==0){cout<<1<<'\n'; exit(0);}
    else{
        tmp%=a;
        if(tmp%b==0){cout<<1<<'\n'; exit(0);}
        else{
            tmp%=b;
            if(tmp%c==0){cout<<1<<'\n'; exit(0);}
        }
    }

    tmp = s;
    if(tmp%a==0){cout<<1<<'\n'; exit(0);}
    else{
        tmp%=a;
        if(tmp%c==0){cout<<1<<'\n'; exit(0);}
        else{
            tmp%=c;
            if(tmp%b==0){cout<<1<<'\n'; exit(0);}
        }
    }

    // 2
    tmp = s;
    if(tmp%b==0){cout<<1<<'\n'; exit(0);}
    else{
        tmp%=b;
        if(tmp%c==0){cout<<1<<'\n'; exit(0);}
        else{
            tmp%=c;
            if(tmp%a==0){cout<<1<<'\n'; exit(0);}
        }
    }

    tmp = s;
    if(tmp%b==0){cout<<1<<'\n'; exit(0);}
    else{
        tmp%=b;
        if(tmp%a==0){cout<<1<<'\n'; exit(0);}
        else{
            tmp%=a;
            if(tmp%c==0){cout<<1<<'\n'; exit(0);}
        }
    }




    // 3
    tmp = s;
    if(tmp%c==0){cout<<1<<'\n'; exit(0);}
    else{
        tmp%=c;
        if(tmp%a==0){cout<<1<<'\n'; exit(0);}
        else{
            tmp%=a;
            if(tmp%b==0){cout<<1<<'\n'; exit(0);}
        }
    }

    tmp = s;
    if(tmp%c==0){cout<<1<<'\n'; exit(0);}
    else{
        tmp%=c;
        if(tmp%b==0){cout<<1<<'\n'; exit(0);}
        else{
            tmp%=b;
            if(tmp%a==0){cout<<1<<'\n'; exit(0);}
        }
    }

    cout<<0<<endl;



}