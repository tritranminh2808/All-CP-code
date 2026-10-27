#include <bits/stdc++.h>
#define int long long
using namespace std;
int par[100005],sz[100005];
int n,m;
set <int> adj[100005];
int find(int u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void add(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
}
priority_queue<pair <int, int > , vector <pair <int, int > > , greater<pair <int, int > > >pq;
int cnt[100005];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        adj[u].insert(v);
        adj[v].insert(u);
        add(u,v);
    }
    for(int i=1;i<=n;i++) pq.push({cnt[i],i});
    int sol=0;
    while(!pq.empty()){
        pair <int, int > p=pq.top();
        pq.pop();
        int x=find(p.second);
        int cc=adj[p.second].size();
        for(auto i:adj[p.second]) adj[i].erase(p.second);
        sol=max(sol,cc*sz[x]);
        // cout <<p.second << " " <<  p.first << " " << sz[x] << "\n";
        sz[x]--;
    }
    cout << sol;
}