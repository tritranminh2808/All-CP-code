#include <bits/stdc++.h>
#define int long long
using namespace std;
int  adj[200005];
bool vst[200005];
int jump[33][200005];
int n,t;
void dfs(int u){
    vst[u]=1;
    if(vst[adj[u]]==1) return;
    jump[0][u]=adj[u];
    dfs(adj[u]);
}
void build(){
    for(int i=1;i<=31;i++){
        for(int j=1;j<=n;j++) jump[i][j]=jump[i-1][jump[i-1][j]];
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin >> n >> t;
    for(int i=1;i<=n;i++) {
        cin >> adj[i];
        jump[0][i]=adj[i];
    }
    build();
    while(t--){
        int u,k; cin >> u >> k;
        for(int i=31;i>=0;i--){
            if(k>=(1LL<<i)){
                k-=(1LL<<i);
                u=jump[i][u];
            }
        }
        cout << u << "\n";
    }
    return 0;
}