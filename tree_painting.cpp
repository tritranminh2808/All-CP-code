#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[4][100005];
const int mod=1e9+7;
int n,k;
vector <int> adj[100005];
int to[100005];
int dfs(int u, int v, int mau){
    if(dp[mau][u]!=-1) return dp[mau][u];
    int ans=1;
    for(auto i:adj[u]){
        if(i!=v){
            int sech=0;
            for(int j=1;j<=3;j++){
                if((to[i]==0||to[i]==j)&&mau!=j){
                    sech+=dfs(i,u,j);
                    sech%=mod;
                }
            }
            ans*=sech;ans%=mod;
        }
    }
    return dp[mau][u]=ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(k--){
        int u,v; cin >> u >> v;
        to[u]=v;
    }
    // dfs(1,0);
    int sol=0;
    for(int i=1;i<=3;i++) sol+=dfs(1,0,i);
    cout << sol%mod;
    return 0;
}