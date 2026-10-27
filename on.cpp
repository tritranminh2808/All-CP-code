#include <bits/stdc++.h>
using namespace std;
struct node{
    node *child[26];
    node (){
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};
node root;
void update (string &s, node &root){
    node *cur=&root;
    for(int i=0;i<s.length();i++){
        int c=s[i]-'a';
        if(!cur->child[c]) cur->child[c]=new node();
        cur=cur->child[c]; 
    }
}
void dfs(node *root){
    for(int i=0;i<26;i++){
        if (root->child[i]) dfs(root->child[i]);
    }
}
int num[200005],low[200005],comp[200005];
bool del[200005];
int timer,cntcomp;
stack <int> st;
vector <int> adj[200005];
void dfs(int u){
    low[u]=num[u]=++timer;
    st.push(u);
    for(auto i:adj[u]){
        if(del[i]) continue;
        if(num[i]) low[u]=min(low[u],num[i]);
        else{
            dfs(i);
            low[u]=min(low[u],low[i]);
        }
    }
    if(low[u]==num[u]){
        int v=0;
        ++cntcomp;
        do{
            v=st.top();
            st.pop();
            comp[v]=cntcomp;
            del[v]=1;
        }while(u!=v);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
} 