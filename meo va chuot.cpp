#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> par[1000005];
int dep[1000005], jump[1000005][18];
void dfs(int u){
	for(auto i : par[u]){
		if(i==jump[u][0]) continue;
		dep[i]=dep[u]+1;
		jump[i][0]=u;
		for (int j = 1; j <=17; ++j) jump[i][j] = jump[jump[i][j - 1]][j - 1];
		dfs(i);
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
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,t; cin >> n >> t;
	for(int i=1;i<n;i++){
		int u,v; cin >> u >> v;
		par[u].push_back(v);
		par[v].push_back(u);
	}
	dfs(1);
//	build(n); //cout << lca (2,5);
	while(t--){
		int a,b,c; cin >> a >> b >> c;
		if(lca(lca(b,c),a)!=lca(b,c)) cout << lca(b,c) << "\n";
		else cout << (lca(a,b)^lca(a,c)^lca(b,c)) << "\n";
	}
}

