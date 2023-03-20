#include<bits/stdc++.h>
using namespace std;
typedef complex<double> base;
int MAX;

void fft(vector<base> &a, bool inv){
    for(int i=1 ; i<MAX ; i++){
        int bit=MAX>>1, j=0;
        for(int k=0 ; 1<<k<MAX ; k++) if(i&1<<k) j|=bit/(1<<k);  
        if(i<j) swap(a[i],a[j]);
    }
    
    for(int i=1 ; i<MAX ; i<<=1){
        double x= inv ? M_PI/i : -M_PI/i;
        base two_based(cos(x),sin(x));
        
        for(int j=0 ; j<MAX ; j+=i<<1){
            base Expo(1,0);
            for(int k=0 ; k<i ; k++){
                base tmp = a[i+j+k]*Expo;
                a[i+j+k] = a[j+k]-tmp;
                a[j+k] += tmp;
                Expo *= two_based;
            }
        }
    }
    
    if(inv) for(int i=0 ; i<MAX ; i++) a[i]/=MAX;
}

void multiply(vector<base> &a, vector<base> &b, vector<int> &res){
    fft(a,0); fft(b,0);
    for(int i=0 ; i<MAX ; i++) a[i] *= b[i];
    fft(a,1);
    for(int i=0 ; i<MAX ; i++) res[i] = round(a[i].real());
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int C; cin>>C;
    while(C--){
        string senior, fan; cin>>senior>>fan;
        int Ssize=senior.size(), Fsize=fan.size();
        
        MAX=1;
        while(MAX<Fsize) MAX<<=1;
        
        vector<base> numone(MAX), numtwo(MAX);
        for(int i=0 ; i<Ssize ; i++) numone[i]=base(senior[i]=='M',0);
        for(int i=0 ; i<Fsize ; i++) numtwo[i]=base(fan[Fsize-i-1]=='M',0);
        
        
        vector<int> res(MAX);
        multiply(numone, numtwo, res);
        
        int ans=0;
        for(int i=Ssize-1 ; i<Fsize ; i++) ans += (!res[i]);
        cout<<ans<<'\n';
    }
}
