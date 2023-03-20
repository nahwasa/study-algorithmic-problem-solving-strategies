#include<bits/stdc++.h>
int i;char S[1010];std::string Z(){std::string a,b,c;a+=S[i];if(S[i++]>'w')b=Z(),c=Z(),a+=Z(),a+=Z();return a+b+c;}int main(){for(scanf("%*d");~scanf("%s",S);std::cout<<Z()<<'\n')i=0;}
