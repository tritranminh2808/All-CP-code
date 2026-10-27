#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector <int> adj[200005];
ll sol=0;
int sz[200005];
void txl(int u, int v){
    sz[u]=1;
    for(auto i:adj[u]){
        if(i==v) continue;
        txl(i,u);
        sz[u]+=sz[i];
    }
}
int n;
void dfs(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
        sol+=1LL*sz[i]*(n-sz[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    txl(1,0);
    // for(int i=1;i<=n;i++) cout << sz[i] << " ";
    dfs(1,0);
    cout << sol;
    return 0;
}