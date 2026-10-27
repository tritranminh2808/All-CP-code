#include <bits/stdc++.h>
using namespace std;
vector <int> adj[200005];
int color[200005];
int n;
set<int> st[200005];
int sol[200005];
void dfs(int u, int v){
    st[u].insert(color[u]);
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
        if(st[i].size()>st[u].size()) swap(st[i],st[u]);
        for(auto i:st[i]) st[u].insert(i);
        st[i].clear();
    }
    sol[u]=st[u].size();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>> n;
    for(int i=1;i<=n;i++) cin >> color[i];
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout << sol[i] << ' ';
    return 0;
}