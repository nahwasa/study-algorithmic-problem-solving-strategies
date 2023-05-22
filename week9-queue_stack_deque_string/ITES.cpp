#include<stdio.h>
#include<string.h>

int main(void)
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int k, n; scanf("%d%d", &k, &n);
		
		int lo=0, hi=0, sum=0, cnt=0;
		unsigned int lo_num=1983, hi_num=1983;
		while(hi<n)
		{
			// printf("%d\n", lo_num%10000+1);
			if(sum < k)
				sum+=hi_num%10000+1, hi_num=(hi_num * 214013 + 2531011), hi++;
			else if(sum > k)
				sum-=lo_num%10000+1, lo_num=(lo_num * 214013 + 2531011), lo++;
			else
				cnt++, sum-=lo_num%10000+1, lo_num=(lo_num * 214013 + 2531011), lo++;
		}
		printf("%d\n", cnt);
	}
}