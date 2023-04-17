// https://www.acmicpc.net/problem/
// MATCHORDER
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
		vector<int> russia(n);
		multiset<int> korea;
		for(int i=0; i<n; i++)
			scanf("%d", &russia[i]);
		for(int j=0; j<n; j++)
		{
			int a; scanf("%d", &a);
			korea.insert(a);
		}

		int ans=0;
		for(auto it : russia)
		{
			auto target=korea.lower_bound(it);
			if(target != korea.end()) ans++, korea.erase(target);
			else korea.erase(korea.begin());
		}
		printf("%d\n", ans);
	}
}

/*
	
*/