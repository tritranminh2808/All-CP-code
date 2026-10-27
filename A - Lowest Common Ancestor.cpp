#include <bits/stdc++.h>
using namespace std;
vector <int> par[1005];
int dep[10005],jump[1005][18];
void dfs(int u, int v){
	for(auto i : par[u]){
		if(i==v) continue;
		dep[i]=dep[u]+1;
		dfs(i,u);
		jump[i][0]=u;
	}
}
void build(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=17;j++) jump[i][j]=jump[jump[i][j-1]][j-1];
	}
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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	int lll=1;
	while(t--){
		for(int i=0;i<1005;i++) par[i].clear();
		int n; cin >> n;
		for(int i=1;i<=n;i++){
			int m; cin >> m;
			while(m--){
				int k; cin >> k;
				par[i].push_back(k);
			}
		}
		dfs(1,0);
		build(n);
		int test; cin >> test;
		cout << "Case " << lll << ":\n";
		while(test--){
			int u,v; cin >> u >> v;
			
			cout << lca(u,v) << "\n";
		}
		lll++;
	}
}
