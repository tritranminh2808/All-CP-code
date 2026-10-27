#include <bits/stdc++.h>
#define int long long
using namespace std;
bool vst[100005];
vector <int> adj[100005];
int n,q;
int sz[100005],dep[100005],jump[100005][18];
void txl(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dep[i]=dep[u]+1;
        jump[i][0]=u;
        txl(i,u);
        // sz[u]+=sz[i];
    }
}
void dfs(int u, int v){
    sz[u]=1;
    for(auto i:adj[u]){
        if(vst[i]||i==v) continue;
        dfs(i,u);
        sz[u]+=sz[i];
    }
}
void build(){
	for(int j=1;j<=17;j++) for(int i=1;i<=n;i++) jump[i][j]=jump[jump[i][j-1]][j-1];
}
int lca(int u, int v){
	if(dep[u]>dep[v]) swap(u,v);
	int dist=dep[v]-dep[u];
	for(int i=17;i>=0;i--){
		if(dist>= (1<<i)){
			dist-=(1<<i);
			v=jump[v][i];
		}
	}
	if(u==v) return u;
	for(int i=17;i>=0;--i){
		if(jump[v][i]==0||jump[u][i]==0) continue;
		if(jump[u][i]!=jump[v][i]){
			u=jump[u][i];
			v=jump[v][i];
		}
	}
	return jump[u][0];
}
int centroid(int u, int v, int tsz){
    for(int i:adj[u]){
        if(vst[i]||i==v) continue;
        if(sz[i]>tsz/2) return centroid(i,u,tsz);
    }
    return u;
}
vector <pair <int, int > > edge;
vector <int> list[100005];
void build_cen(int u, int v){
    dfs(u,0);
    int x=sz[u];
    int tam=centroid(u,0,x);
    vst[tam]=1;
    if(v!=0) edge.push_back({v,tam});
    for(auto i: adj[tam]) if(!vst[i]) build_cen(i,tam);
}
multiset<int> st[100005];
vector <int> lit[100005];
void dfs2(int u, int v){
    // cout << u << " ";
    for(auto i:adj[u]){
        if(i==v) continue;
        for(auto j:lit[u]) lit[i].push_back(j);
        lit[i].push_back(u);
        dfs2(i,u);
    }
}
bool color[100005];
void update(int u){
    if(color[u]==0){
        color[u]=1;
        for(auto i:lit[u]) st[i].insert(dep[u]+dep[i]-2*dep[lca(i,u)]);
    }
    else {
        color[u]=0;
        for(auto i:lit[u]){
            int val=dep[u]+dep[i]-2*dep[lca(i,u)];
            auto it = st[i].find(val); if(it!=st[i].end()) st[i].erase(it);
        }
    }
}
int find(int u){
    int res=INT_MAX;
    for(auto i:lit[u]) {
        int dist=dep[u]+dep[i]-2*dep[lca(i,u)]+*st[i].begin();
        res=min(res,dist);
    }
    if(res>=INT_MAX) return -1;
    else return res;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    txl(1,0);
    dfs(1,0);
    build();
    int root=centroid(1,0,sz[1]);
    // return 0;
    build_cen(1,0);
    for(int i=1;i<=n;++i) adj[i].clear();
    // return 0;
    // cout << root << "\n";        
    for(auto i:edge) {
        // cout << i.first << " " << i.second << "\n";
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    dfs2(root,0);
    for(int i=1;i<=n;i++) {
        lit[i].push_back(i);
        st[i].insert(INT_MAX);
    }
    int q; cin >> q;
    while(q--){
        int typ; cin >> typ;
        if(!typ){
            int u; cin >> u;
            update(u);
        }
        else{
            int u; cin >> u;
            cout << find(u) << "\n";
        }
    }
    return 0;
}