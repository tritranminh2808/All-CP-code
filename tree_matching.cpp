#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[2][200005];
const int mod=1e9+7;
int n,k;
vector <int> adj[200005],adj2[200005];
int to[200005];
bool vst[200005];
int dep[200005];
void dfs(int u, int v ){
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
        dp[0][u]+=max(dp[1][i],dp[0][i]);
    }
    for(auto i:adj[u]){
        if(i==v) continue;
        dp[1][u]=max(dp[1][u],1+dp[0][i]+dp[0][u]-max(dp[0][i],dp[1][i]));
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << max(dp[1][1],dp[0][1]);
    return 0;
}