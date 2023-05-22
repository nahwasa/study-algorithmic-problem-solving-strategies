#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

static inline unsigned long custom_strstr(const char* a, const char* b, int i)
{
	static char tmp[20001];
	if(i%2==0)
	{
		// find a in b
		strcpy(tmp, b);
		strcat(tmp, b);
		return (unsigned long)strstr(tmp, a)-(unsigned long)tmp;
	}
	else
	{
		// find b in a
		strcpy(tmp, a);
		strcat(tmp, a);
		return (unsigned long)strstr(tmp, b)-(unsigned long)tmp;
	}
}

int main(void)
{
	int t; scanf("%d", &t);
	// char tmp[10001];
	while(t--)
	{
		int n; scanf("%d", &n);
		char s[20001];
		scanf("%s", s);
		size_t len=strlen(s);
		// strcpy(tmp, s);
		// strcat(s, tmp);
		
		int ans=0;
		for(int i=0; i<n; i++)
		{
			char target[10001];
			scanf("%s", target);
			int ptr=custom_strstr(s, target, i);//-s;
			assert(ptr>0);
			ans+=ptr;
			// if(i%2==0)
			// 	ans+=len-ptr;
			// else
			// 	ans+=ptr;
				
			strcpy(s, target);
			// strcpy(tmp, target);
			// strcat(s, tmp);
		}
		printf("%d\n", ans);
	}
}