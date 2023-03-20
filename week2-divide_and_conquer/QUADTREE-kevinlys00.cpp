#include<bits/stdc++.h>
using namespace std;
int i;char S[1010];

string Z(){
    string a,b,c,d,e;
    a+=S[i];
    if(S[i++]=='x'){
        b=Z();
        c=Z();
        d=Z();
        e=Z();
    }
    
    return a+d+e+b+c;
}

int main(){
    int C; cin>>C;
    while(C--){
        cin>>S;
        i=0;
        cout<<Z()<<'\n';
    }
}
