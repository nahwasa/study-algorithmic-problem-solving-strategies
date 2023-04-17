// https://www.acmicpc.net/problem/
// LUNCHBOX
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		vector<pair<int,int> > arr(n);
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i].second);
		for(int j=0; j<n; j++)
			scanf("%d", &arr[j].first);
		
		sort(arr.begin(), arr.end(), greater<pair<int,int> >());

		int ans=0, _time=0;
		for(int i=0; i<n; i++)
		{
			_time+=arr[i].second;
			ans=max(ans, _time+arr[i].first);
		}
		printf("%d\n", ans);
	}
}

/*
	
*/