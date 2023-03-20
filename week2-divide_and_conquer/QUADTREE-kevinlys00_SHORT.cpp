#include<bits/stdc++.h>
int i;char S[1010];std::string Z(){std::string a,b,c,d,e;a+=S[i];if(S[i++]>'w')b=Z(),c=Z(),d=Z(),e=Z();return a+d+e+b+c;}int main(){for(scanf("%*d");~scanf("%s",S);std::cout<<Z()<<'\n')i=0;}
