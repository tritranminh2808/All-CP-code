#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
set <pair <int, int > > adj[100005];
int num[100005],low[100005],bel[100005],sz[100005],dem[100005];
int cnt=0,cc=0;
bool del[100005];
stack <int> st;
int comp[100005],cntcomp=0;
int khop=0;
vector <pair <int, int > > cau;
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
                if(low[i.first]>num[u]) cau.push_back({i.first,u});
            }
        }
    }
}
int par[100005];
int find(int i){
    if ( par[i]==i) return i;
    return par[i]=find(par[i]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v; 
        cin >> u >> v;
        adj[u].insert({v,i});
        adj[v].insert({u,i});
    }
    for(int i=1;i<=n;i++) if(!num[i]) dfs(i,0);
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
    for(auto i:cau){
        int u=i.first,v=i.second;
        u=find(u);
        v=find(v);
        if(u==v) continue;
        add(u,v);
    }
    
    set<int> st;
    for(int i=1;i<=n;i++) st.insert(find(i));
    long long sol=0;
    for(auto i:st) sol+=(sz[i]-1)*(sz[i]-2)/2;
    cout << sol;
}