#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> adj[200005];
int dep[200005],maxx[200005],up[20][200005],val[20][200005],w[200005];
void dfs(int u, int v){
    // sz[u]=1;
    for(auto i:adj[u]){
        if(i==v) continue;
        dep[i]=dep[u]+1;
        dfs(i,u);
        maxx[u]=max(maxx[u],maxx[i]+1);
        up[0][i]=u;
        // val[0][i]=
    }
    // val[0][u]=maxx[u]-dep[u];
}
void bui(int u, int v){
    int m1=0,m2=0;
    for(auto i:adj[u]){
        if(i==v) continue;
        int c=maxx[i]+1;
        if(c>m1){
            m2=m1;
            m1=c;
        }
        else if(c>m2) m2=c;
    }
    for(auto i:adj[u]){
        if(i==v) continue;
        int c=maxx[i]+1;
        int sech=0;
        if(c==m1) sech=m2;
        else sech=m1;
        if(sech<0) sech=0;
        w[i]=sech-dep[u];
    }
    for(auto i:adj[u]){
        if(i==v) continue;
        bui(i,u);
    }
}
void cok(){
    cin >> n;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        dep[i]=0;
        maxx[i]=0;
        for(int j=0;j<20;j++) {
            up[j][i]=0;
            val[j][i]=-INT_MAX;
        }
    }
    w[1]=-INT_MAX;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    bui(1,0);
    for(int i=1;i<=n;i++) val[0][i]=w[i];
    for(int i=1;i<=19;i++){
        for(int j=1;j<=n;j++){
            up[i][j]=up[i-1][up[i-1][j]];
            val[i][j]=max(val[i-1][j],val[i-1][up[i-1][j]]);
        }
    }
    int q; cin >> q;
    while(q--){
        int v,k; cin >> v >> k;
        k=min(k,dep[v]);
        int g=dep[v];
        int res=maxx[v]-dep[v];
        for(int i=19;i>=0;i--){
            if(k>=(1<<i)){
                k-=(1<<i);
                res=max(res,val[i][v]);
                v=up[i][v];
            }
        }
        cout << g+res << " ";
    }
    cout << "\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cok();
    }
}