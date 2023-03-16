// 6-8 CLOCKSYNC
// https://algospot.com/judge/problem/read/CLOCKSYNC
// 2021-06-30 03:31:35
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

vector<int> curr_time;

int time_check()
{
    for(int i=0; i<16; i++)
        if(curr_time[i]!=0)
            return 1;
    return 0;
}
int get_ans(int idx)
{
    if(idx==10)
        return time_check() ? INT32_MAX/2 : 0;

    int candidate=INT32_MAX/2;
    for(int i=0; i<4; i++)
    {
        candidate=min(candidate, i+get_ans(idx+1));
        for(int j : button[idx])
            curr_time[j]=(curr_time[j]+3)%12;
    }
    return candidate;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        curr_time=vector<int>(16, 0);

        for(int i=0; i<16; i++)
            scanf("%d", &curr_time[i]);

        for(int i=0; i<16; i++)
            curr_time[i]%=12;

        int ans=get_ans(0);
        printf("%d\n", ans==INT32_MAX/2 ? -1:ans);
    }    
}
