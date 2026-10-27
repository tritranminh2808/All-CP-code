#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n,m;
set <pair <int, int > > adj[100005];
int num[100005],low[100005],bel[100005],dem[100005];
int cnt=0,cc=0;
bool del[100005];
stack <int> st;
int comp[100005],cntcomp=0;
bool cau[300005];
int par[100005],sz[100005];
void dfs(int u,int p){
    int cntchild=0;
    num[u]=low[u]=++cnt;
    for(auto i:adj[u]){
       
        if(i.second!=p){
            if(num[i.first])  low[u]=min(low[u],num[i.first]);
            else {
                dfs(i.first,i.second);
                cntchild++;
                low[u]=min(low[u],low[i.first]);
                if(low[i.first]>num[u]) cau[i.second]=1;
            }
        }
    }
}
int find(int u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
}
int deg[1000005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector <pair <int, int > > edge;
    for(int i=1;i<=m;i++){
        int u,v; 
        cin >> u >> v;
        edge.push_back({u,v});
        adj[u].insert({v,i});
        adj[v].insert({u,i});
    }
    for(int i=1;i<=n;i++) if(!num[i]) dfs(i,0);
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
    // for(int i=1;i<=m;i++) if(cau[i]) cout << i << " ";
    for(int i=0;i<m;i++){
        if(!cau[i+1]){
            int u=edge[i].first,v=edge[i].second;
            // cout << u << " " << v << endl;
            u=find(u);
            v=find(v);
            if(u==v) continue;
            add(u,v);
        }
    }
    set<int> st;
    for(auto i:edge){
        int u=i.first , v=i.second;
        u=find(u);
        v=find(v);
        st.insert(u);
        st.insert(v);
        if(u!=v) {
            deg[u]++;
            deg[v]++;
        }
    }
    int sol=0;
    for(auto i:st) if(deg[i]==1) sol++;
    cout << (sol+1)/2;
}