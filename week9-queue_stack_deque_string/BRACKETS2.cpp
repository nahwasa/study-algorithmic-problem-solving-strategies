#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[10001];
    int stk[10001];
    int t; scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        int len=strlen(s), flag=0, hi=0;
        for(int i=0; i<len; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')  
                stk[hi++]=s[i];
            else
            {	
                if(hi && s[i] == ')' && stk[hi-1]=='(')
                    hi--;
                else if(hi && s[i] == '}' && stk[hi-1]=='{')
                    hi--;
                else if(hi && s[i] == ']' && stk[hi-1]=='[')
                    hi--;
				else
				{
					flag=1;
					break;
				}
            }
        }
        if(flag || hi) printf("NO\n");
        else printf("YES\n");
    }
}