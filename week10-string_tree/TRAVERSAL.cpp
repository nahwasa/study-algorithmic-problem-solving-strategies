// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

/*
27 / 16 9 12 / 54 36 72 <- pre
9 12 16 / 27 / 36 54 72 <- in
        3
a to 3 and 4 to b
*/

// convert pre/inorder to postorder
int convert(int a, int b, int x, int y, vector<int>& pre, vector<int>& in)
{
    #ifdef LOCAL
        // printf("%d %d %d %d\n", a, b, x, y);
    #endif
    if(a==b) return 0;

    auto root_in_inorder=find(in.begin()+x, in.begin()+y, pre[a])-in.begin();
    convert(a+1, a+root_in_inorder-x+1, x, root_in_inorder, pre, in); // left
    convert(a+root_in_inorder-x+1, b, root_in_inorder+1, y, pre, in); // right
    printf("%d ", pre[a]);
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> pre(n), in(n);
        for(int i=0; i<n; i++)
            scanf("%d", &pre[i]);
        for(int j=0; j<n; j++)
            scanf("%d", &in[j]);

        convert(0, n, 0, n, pre, in);
        printf("\n");
    }
}

/*
    
*/