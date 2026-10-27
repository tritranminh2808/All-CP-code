#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
//#define int long long
using namespace std;
int n,q;
vector <int > adj[100005];
int dep_goc[100005],sz[100005];
int up[20][100005];
void dfs(int u,int v){
	for(auto i:adj[u]){
		if(i==v) continue;
        up[0][i]=u;
		dep_goc[i]=dep_goc[u]+1;
		dfs(i,u);
	}
}
void build_lca(){
    for(int i=1;i<=18;i++){
        for(int j=1;j<=n;j++) up[i][j]=up[i-1][up[i-1][j]];
    }
}
int lca(int u, int v){
    if(dep_goc[u]>dep_goc[v]) swap(u,v);
    int dist=dep_goc[v]-dep_goc[u];
    for(int i=18;i>=0;i--){
        if(dist>=(1<<i)){
            dist-=(1<<i);
            v=up[i][v];
        }
    }
    if(v==u) return u;
    for(int i=18;i>=0;i--){
        if(up[i][u]==0||up[i][v]==0) continue;
        if(up[i][u]!=up[i][v]){
            u=up[i][u];
            v=up[i][v];
        }
    }
    return up[0][u];
}
bool vst[100005];
void dfs_sz(int u, int v){
    sz[u]=1;
    for(auto i:adj[u]){
        if(i==v||vst[i]) continue;
        dfs_sz(i,u);
        sz[u]+=sz[i];
    }
}
int centroid(int u, int v, int kichthuoc){
    for(auto i:adj[u]){
        if(i==v||vst[i]) continue;
        if(sz[i]>kichthuoc/2) return centroid(i,u,kichthuoc);
    }
    return u;
}

vector <pair <int, int > > edge;
void build(int u, int v){
    dfs_sz(u,0);
    int tam=centroid(u,0,sz[u]);
    vst[tam]=1;
    if(v!=0) edge.push_back({tam,v});
    for(auto i:adj[tam]) if(!vst[i]) build(i,tam);
}
int minn[100005],dep2[100005],par[100005];
void txlctt(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dep2[i]=dep2[u]+1;
        txlctt(i,u);
    }
}
void txl_par(int u,int v){
    for(auto i:adj[u]){
        if(dep2[i]<dep2[u]){
            par[u]=i;
            continue;
        }
        txl_par(i,u);
    }
}
void update(int u){
    int x=u,cnt=0;
    while(x!=0){
        minn[x]=min(minn[x],dep_goc[u]+dep_goc[x]-2*dep_goc[lca(u,x)]);
        x=par[x];
    }
}
int query(int u){
    int ans=INT_MAX;
    int x=u;
    while(x!=0){
        ans=min(ans,dep_goc[u]+dep_goc[x]-2*dep_goc[lca(u,x)]+minn[x]);
        x=par[x];
    }
    return ans;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>> q;
	for(int i=1;i<n;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
    build_lca();
    dfs_sz(1,0);
    int goc=centroid(1,0,n);
    build(1,0);
    for(int i=1;i<=n;i++) minn[i]=INT_MAX;
    minn[1]=0;
    // for(auto i:edge) cout << i.first << " " << i.second << "\n";
    for(int i=1;i<=n;i++)adj[i].clear();
    for(auto i:edge){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    txlctt(goc,0);
    txl_par(goc,0);
    update(1);
    // for(int i=1;i<=n;i++) cout << minn[i] << endl;
    while(q--){
        int t,u; cin >> t >> u;
        if(t==1) update(u);
        else cout << query(u) << "\n";
    }   
	return 0;
}
