// https://www.acmicpc.net/problem/
// 2023-05-31 18:15:36
#include"bits/stdc++.h"
using namespace std;

int d;/*for cmp_sa*/
vector<int> pos/*group number*/, sa/*start location*/;

int cmp_sa(int a, int b)
{
    if(pos[a]!=pos[b]) return pos[a]<pos[b];
    a+=d, b+=d;
    if(a<pos.size() and b<pos.size()) return pos[a]<pos[b];
    else return a>b;
}

void get_sa(string& s)
{
    int n=s.length();
    pos.assign(n, 0), sa.assign(n, 0);
    for(int i=0; i<n; i++)
        pos[i]=s[i], sa[i]=i;
    
    d=1;
    while(true)
    {
        sort(sa.begin(), sa.end(), cmp_sa);

        vector<int> tmp(n);
        for(int i=1; i<n; i++)
            tmp[i]=tmp[i-1]+cmp_sa(sa[i-1], sa[i]);
        for(int i=0; i<n; i++)
            pos[sa[i]]=tmp[i];
        
        if(tmp.back() == n-1) break;
        d*=2;
    }
}

vector<int> get_lcp(string& s)
{
    int n=s.size();
    vector<int> lcp(n);

    for(int i=0, k=0; i<n; i++, k=max(k-1, 0))
    {
        if(pos[i]==0) continue; // first idx
        
        int j=sa[pos[i]-1];
        while(s[j+k] == s[i+k]) k++;
        lcp[pos[i]]=k;
    }
    return lcp;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t=0; scanf("%d", &t);
    while(t--)
    {
        int k; scanf("%d", &k);
        string s; cin >> s;
        get_sa(s);
        auto lcp=get_lcp(s);

        #ifdef LOCAL
            for(int i=0; i<s.length(); i++)
                printf("%d ", lcp[i]);
            printf("\n");

            for(int i=0; i<s.length(); i++)
                printf("%s\n", s.c_str()+sa[i]);
            printf("\n");
        #endif

        int lo=0, hi=s.length(), ans=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            int flag=0;
            {
                // k번 이상 연속으로 반복되는 길이가 mid이상인 문자열이 있는가?
                int tmp=1;
                for(int i=0; i<s.length(); i++)
                {
                    if(lcp[i]>=mid) tmp++;
                    else tmp=1;

                    if(tmp>=k) flag=1;
                }
            }
            if(flag)
                lo=mid+1, ans=mid;
            else
                hi=mid-1;
        }
        printf("%d\n", ans);
    }
}

/*

*/