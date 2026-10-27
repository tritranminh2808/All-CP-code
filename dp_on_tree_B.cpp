#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
vector <int> adj[100005];
ll dp1[100005],dp2[100005];
int mod;
pair <int, int > val[100005];
void reset(int n){
    for(int i=1;i<=n;i++){
        adj[i].clear();
        dp1[i]=1;
    }
    dp2[1]=1;
}
void dfs1(int u,int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs1(i,u);
        dp1[u]=(dp1[u]*(dp1[i]+1))%mod;
    }
}
void dfs2(int u, int v){
    int sz=adj[u].size();
    vector <ll> pre(sz+1,1),suf(sz+1,1);// pre la pre tu 0 den i-1, suf la suf tu sz-1 den i
    for(int i=0;i<sz;i++){
        if(adj[u][i]==v) pre[i+1]=(pre[i]*dp2[u])%mod;
        else pre[i+1]=(pre[i]*(dp1[adj[u][i]]+1))%mod;
    }
    for(int i=sz-1;i>=0;i--){
        if(adj[u][i]==v) suf[i]=(suf[i+1]*dp2[u])%mod;
        else suf[i]=(suf[i+1]*(dp1[adj[u][i]]+1))%mod;
    }
    for(int i=0;i<sz;i++){
        if(adj[u][i]==v) continue;
        dp2[adj[u][i]]=(pre[i]*suf[i+1]+1)%mod;
        dfs2(adj[u][i],u);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n >> mod;
    reset(n);
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout << dp1[i]*dp2[i]%mod << "\n";
    return 0;
}