#include<bits/stdc++.h>
int i;char S[1010];std::string Z(){std::string a,b;a+=S[i];if(S[i++]>'w')b=Z(),b+=Z(),a+=Z(),a+=Z()+b;return a;}int main(){for(scanf("%*d");~scanf("%s",S);std::cout<<Z()<<'\n')i=0;}
