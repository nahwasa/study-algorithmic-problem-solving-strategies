// https://www.acmicpc.net/problem/17472
// 2021-05-16 01:50:16 0ms
#include<bits/stdc++.h>
using namespace std;

const int mov[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
vector<vector<int> > arr;
vector<int> parent;
int n,m,cnt=2;

void dfs(int i, int j)
{
    arr[i][j]=cnt;
    for(int way=0; way<4; way++)
    {
        int ni=i+mov[way][0], nj=j+mov[way][1];
        if(ni>0 && ni<=n && nj>0 && nj<=m) // 이동가능하면
            if(arr[ni][nj]==1) // 같은 섬이라면
                dfs(ni,nj);
    }
}

int find(int a)
{
    if(parent[a]>=0)
    {
        int tmp=a;
        while(parent[a]>=0)
            a=parent[a];
        parent[tmp]=a;
    }
    return a;
}

int merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b)
        return 1;
    
    if(parent[a]>parent[b])
        swap(a,b);
    
    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int main(void)
{
    scanf("%d%d", &n,&m);

    arr.assign(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &arr[i][j]);
    
    // 각 섬에 번호 매기기
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(arr[i][j]==1) // 방문 안 한 섬이라면
            {
                dfs(i,j); // 탐색
                cnt++;
            }
    
    parent.assign(cnt, -1);
    
    // 간선찾기
    vector<pair<int, pair<int,int> > > edge; // dist, a,b 
    for(int i=1; i<=n; i++)
    {
        int prev=-1, loca=INT32_MIN;
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j]!=0)
            {
                if(arr[i][j]==prev || prev==-1)
                    loca=j, prev=arr[i][j];
                else
                {
                    if(j-loca-1 > 1)
                        edge.push_back({j-loca-1, {arr[i][j], prev}});
                    loca=j, prev=arr[i][j];
                }

            }
        }
    }

    for(int i=1; i<=m; i++)
    {
        int prev=-1, loca=INT32_MIN;
        for(int j=1; j<=n; j++)
        {
            if(arr[j][i]!=0)
            {
                if(arr[j][i]==prev || prev==-1)
                    loca=j, prev=arr[j][i];
                else
                {
                    if(j-loca-1 > 1)
                        edge.push_back({j-loca-1, {arr[j][i], prev}});
                    loca=j, prev=arr[j][i];
                }

            }
        }
    }

    sort(edge.begin(), edge.end());
    int sum=0, e_count=0;
    for(pair<int, pair<int,int> > e : edge)
    {
        if(merge(e.second.first, e.second.second)==0)
            sum+=e.first, e_count++;
        if(cnt-2-e_count==1)
            break;
    }
    printf("%d", cnt-2-e_count==1 ? sum:-1);
}
