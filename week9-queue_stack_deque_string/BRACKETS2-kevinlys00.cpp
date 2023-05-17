#include<bits/stdc++.h>
using namespace std;

int main(){
    int c; cin>>c;
    while(c--){
        string s; cin>>s;
        stack<char> chk; bool pos=true;
        
        for(char& i : s){
            if(i=='('||i=='{'||i=='[') chk.push(i);
            else{
                if(chk.empty()){pos=false; break;}
                if(i==')'){
                    if(chk.top()=='('){chk.pop(); continue;}
                    else{pos=false; break;}
                }
                else if(i=='}'){
                    if(chk.top()=='{'){chk.pop(); continue;}
                    else{pos=false; break;}
                }
                else if(i==']'){
                    if(chk.top()=='['){chk.pop(); continue;}
                    else{pos=false; break;}
                }
            }
        }
        
        cout<<(pos&chk.empty()?"YES\n":"NO\n");
    }
}
