#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int cc1=INT_MAX;
const int p=1e6+5;
int par[p],a[p],minn[p];
vector <int> sz(p,1);
int find(int u){
	if(par[u]==u) return u;
	else {
		par[u]=find(par[u]);
		return par[u];
	}
}
void add(int u, int v){
	u=find(u);v=find(v);
	if(u==v) return ;
	else {
		if(sz[u]>=sz[v]) {
			par[v]=u;
			sz[u]+=sz[v];
		}
		else {
			par[u]=v;
			sz[v]+=sz[u];
		}
	}
}
vector <int> adj[200005];
int sol=0;
bool loc[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
//	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) par[i]=i;
	while(m--){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while(k--){
		char q; cin >> q;
		if(q=='X'){
			int i; cin >> i;
			loc[i]=1;
			for(auto j:adj[i]) if(loc[j]) add(i,j);
		}
		else{
			int s,t; cin >> s >> t;
//			cout << find(s) << " " << find(t) << endl;
			if(find(s)==find(t)) cout << "Y";
			else cout << "N";
		}
	}
	return 0;
}
