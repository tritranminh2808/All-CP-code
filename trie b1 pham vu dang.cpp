#include <bits/stdc++.h>
using namespace std;
struct node{
    node *child[26];
    int cnt;
    node(){
        for(int i=0;i<26;i++) child[i]=NULL;
        cnt=0;
    }
};
node root;
void update(string &s, node &root){
    node *cur=&root;
    for(auto i:s){
        int c=i-'a';
        if(!cur->child[c]) cur->child[c]=new node();
        cur=cur->child[c];
    }
    cur->cnt++;
}
int ans=0;
void dfs(node *u){
    // node *cur=&root;
    ans=max(ans,u->cnt);
    for(int i=0;i<26;i++){
        if(u->child[i]){
            u->child[i]->cnt+=u->cnt;
            dfs(u->child[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        update(s,root);
    }
    dfs(&root);
    cout << ans;
    return 0;
}