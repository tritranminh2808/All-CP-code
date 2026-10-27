#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int par[100005],sz[100005];
int find(int u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        add(u,v);
    }
    while(q--){
        int u,v; cin >> u >> v;
        if(find(u)==find(v)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
