//tree + dfs
#include<bits/stdc++.h>
using namespace std;

struct QUAD{
    char color;
    int sub[4];
    int parent;
};

void dfs(vector<QUAD>& tree, int idx){
    char IS_ALL=tree[idx].color;
    cout<<IS_ALL;
    if(IS_ALL^'x') return;
    for(int i=0 ; i<4 ; i++) dfs(tree,tree[idx].sub[i]);
}

int main(){
    int C;
    for(cin >> C ; C-- ; ){
        string s; cin>>s;
        int length = s.size(), tree_max=1;
        vector<QUAD> tree(length);
        
        for(int i=0, idx=0 ; i<length ; i++){
            tree[idx].color=s[i];
            if(s[i]=='x'){
                for(int z=0 ; z<4 ; z++) tree[tree_max+z].parent=idx;
                tree[idx].sub[0]=tree_max+2;
                tree[idx].sub[1]=tree_max+3;
                tree[idx].sub[2]=tree_max;
                tree[idx].sub[3]=tree_max+1;
                idx=tree_max;
                tree_max+=4;
            }
            else{
                while(idx && !(idx&3)) idx=tree[idx].parent;
                idx++;
            }
        }
        
        dfs(tree,0);
        cout<<'\n';
    }
}
