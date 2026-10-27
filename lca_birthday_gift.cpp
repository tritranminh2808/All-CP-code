#include <bits/stdc++.h>
using namespace std;
int n,m,q;
vector <int> adj[200005];
int a[2000005],dep[2000005],up[20][200005];
set <int> luu[200005],pos[200005];
void dfs(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dep[i]=dep[u]+1;
        up[0][i]=u;
        dfs(i,u);
    }
}
void build(){
    for(int i=1;i<=19;i++) for(int j=1;j<=n;j++) up[i][j]=up[i-1][up[i-1][j]];
}
int lca(int u, int v){
    if(dep[u]>dep[v]) swap(u,v);
    int dist=dep[v]-dep[u];
    for(int i=19;i>=0;i--){
        if(dist>=(1<<i)){
            dist-=(1<<i);
            v=up[i][v];
        }
    }
    if(v==u) return u;
    for(int i=19;i>=0;i--){
        if(up[i][u]==0||up[i][v]==0) continue;
        if(up[i][u]!=up[i][v]){
            u=up[i][u];
            v=up[i][v];
        }
    }
    return up[0][u];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=m;i++) cin >> a[i];
    dfs(1,0);
    build();
    for(int i=1;i<m;i++)  {
        luu[lca(a[i],a[i+1])].insert(i);
        pos[a[i]].insert(i);
    }
    pos[a[m]].insert(m);
    while(q--){
        int typ; cin >> typ;
        if(typ==1){
            int u,v; cin >> u >> v;
            if(u>1){
                int g2=lca(a[u-1],a[u]),g4=lca(a[u-1],v);
                luu[g2].erase(u-1);
                luu[g4].insert(u-1);
            }
            if(u<m){
                int g1=lca(a[u],a[u+1]),g3=lca(v,a[u+1]);
                luu[g1].erase(u);
                luu[g3].insert(u);
            }
            pos[a[u]].erase(u);
            pos[v].insert(u);
            a[u]=v;            
            
        }   
        else{
            int l,r,v; cin >> l >> r >> v;
            auto it = luu[v].lower_bound(l);
            if(it!=luu[v].end() && *it < r) cout<< *it << " " << (*it+1) << "\n";
            else {
                auto it2=pos[v].lower_bound(l);
                if(it2!=pos[v].end()&&*it2<=r) cout << *it2 << " " << *it2 << "\n";
                else cout<< "-1 -1\n";
            }
        }
    }
    return 0;
}