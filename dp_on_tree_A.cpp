#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
vector <int> adj[100005];
ll dp[2][100005];
pair <int, int > val[100005];
void reset(int n){
    for(int i=1;i<=n;i++){
        dp[0][i]=0;
        dp[1][i]=0;
        adj[i].clear();
    }
}
void dfs(int u,int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
        dp[0][u]+=max(dp[1][i]+abs(val[i].second-val[u].first),dp[0][i]+abs(val[i].first-val[u].first));
        dp[1][u]+=max(dp[1][i]+abs(val[i].second-val[u].second),dp[0][i]+abs(val[i].first-val[u].second));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        reset(n);
        for(int i=1;i<=n;i++) cin >> val[i].first >> val[i].second;
        for(int i=1;i<n;i++){
            int u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0);
        cout << max(dp[1][1],dp[0][1]) << "\n";
    }
    return 0;
}