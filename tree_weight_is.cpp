#include <bits/stdc++.h>
#define int long long
using namespace std;
pair <int, int >  dp[2][200005];
const int mod=1e9+7;
int n,k;
vector <int> adj[200005];
int a[200005];
void dfs(int u, int v ){
    dp[0][u].first=0;
    dp[1][u].first=1;
    dp[0][u].second=0;
    dp[1][u].second=a[u];
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
        if(dp[1][i].first>dp[0][i].first){
            dp[0][u].first+=dp[1][i].first;
            dp[0][u].second+=dp[1][i].second;
        }
        else if(dp[1][i].first<dp[0][i].first){
            dp[0][u].first+=dp[0][i].first;
            dp[0][u].second+=dp[0][i].second;
        }
        else{
            dp[0][u].first+=dp[0][i].first;
            dp[0][u].second+=max(dp[0][i].second,dp[1][i].second);
        }
        dp[1][u].first+=dp[0][i].first;
        dp[1][u].second+=dp[0][i].second;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> a[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    if(dp[1][1].first>dp[0][1].first) cout << dp[1][1].second;
    else if(dp[1][1].first<dp[0][1].first)cout << dp[0][1].second;
    else cout << max(dp[1][1].second,dp[0][1].second);
    return 0;
}