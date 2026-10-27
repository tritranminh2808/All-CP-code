#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> adj[100005];
bool meo[100005];
int sol=0;
void dfs(int u, int v, int cnt){
    
    if(meo[u]) cnt++;
    else cnt=0;
    // cout << u << " " << cnt << "\n";
    if(cnt>m) return;
    if(adj[u].size()==1&&u!=1) sol++;
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u,cnt);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> meo[i];
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);
    cout << sol;
    return 0;
}
