#include <bits/stdc++.h>
using namespace std;
int sz[100005];
vector <int> adj[100005];
bool vst[100005];
int n;
void dfs(int u, int v){
    sz[u]=1;
    for(auto i:adj[u]){
        if(i==v||vst[i]) continue;
        dfs(i,u);
        sz[u]+=sz[i];
    }
}
int centroid(int u,int v, int kichthuoc){
    for(int i:adj[u]){
        if(i==v||vst[i]) continue;
        if(sz[i]>kichthuoc/2) return centroid(i,u,kichthuoc);
    }
    return u;
}
vector <pair <int, int > > edge;
void build_centroid(int u, int v){
    dfs(u,0);
    int x=sz[u];
    int tam=centroid(u,0,x);
    vst[tam]=1;
    if(v!=0) edge.push_back({v,tam});
    for(auto i:adj[tam]) if(!vst[i]) build_centroid(i,tam);
}
int dep[100005];
void dfs2(int u,int v){
    // cout << u << " ";
    for(auto i:adj[u]){
        if(i==v) continue;
        dep[i]=dep[u]+1;
        dfs2(i,u);
    }
}
int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int goc=centroid(1,0,n);
    build_centroid(1,0);
    for(int i=1;i<=n;i++) adj[i].clear();
    for(auto i:edge) {
        // cout << i.first << " " << i.second << "\n";
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    dfs2(goc,0);
    for(int i=1;i<=n;i++) cout << char('A'+dep[i]) << " ";
    return 0;
}