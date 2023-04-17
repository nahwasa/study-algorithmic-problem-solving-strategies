// https://www.acmicpc.net/problem/
// STRJOIN
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int t; scanf("%d", &t);
	while(t--)
	{
		priority_queue<int, vector<int>, greater<int> > pq;
		int n; scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			int a; scanf("%d", &a);
			pq.push(a);
		}

		int ans=0;
		while(pq.size() != 1)
		{
			int a=pq.top(); pq.pop();
			int b=pq.top(); pq.pop();
			ans+=a+b;
			pq.push(a+b);
		}
		printf("%d\n", ans);
	}
}

/*
	
*/