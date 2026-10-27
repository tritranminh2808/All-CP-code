#include <bits/stdc++.h>
using namespace std;
vector <int> par[100005];
int dep[100005],jump[100005][24];
void dfs(int u){
	for(auto i : par[u]){
		if(i==jump[u][0]) continue;
		dep[i]=dep[u]+1;
		jump[i][0]=u;
		for (int j = 1; j <=17; ++j) jump[i][j] = jump[jump[i][j - 1]][j - 1];
		dfs(i);
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
	freopen("nutchachung.inp","r",stdin);
	freopen("nutchachung.out","w",stdout);
	int n,k; cin >> n >> k;
	for(int i=1;i<n;i++){
		int m,mm; cin >> m >> mm;
		par[m].push_back(mm);
		par[mm].push_back(m);
	}
	dfs(1);
//	build(n);	
	int u,v; cin >> u >> v;	
	cout << lca(u,v);
}
