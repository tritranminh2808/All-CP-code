#include <bits/stdc++.h>
using namespace std;
struct node{
    node *child[26];
    int cnt;
    node(){
        cnt=0;
        for(int i=0;i<=25;i++) child[i]=NULL;
    }
};
node root;
void add(const string &a, node &root){
    node *cur=&root;
    for(int i=0;i<a.size();i++){
        if(!(cur->child[a[i]-'a'])) cur->child[a[i]-'a']=new node();
        cur=cur->child[a[i]-'a'];
    }
    cur->cnt++;
}
int cnt=0;
void dfs(node *v){
    cnt++;
    for(int i=0;i<=25;i++){
        if(v->child[i]) {
            dfs(v->child[i]);
            // v->cnt+=v->child[i]->cnt;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>> q;
    while(q--){
        string s; cin >> s;
        add(s,root);
    }
    dfs(&root);
    cout << cnt;
    return 0;
}