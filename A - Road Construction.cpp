#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
int par[p];
vector <int> sz(p,1);
int find(int u){
	if(par[u]==u) return u;
	else {
		par[u]=find(par[u]);
		return par[u];
	}
}
int add(int u, int v){
	u=find(u);v=find(v);
	if(u==v) return 0;
	else {
		if(sz[u]>=sz[v]) {
			par[v]=u;
			sz[u]+=sz[v];
		}
		else {
			par[u]=v;
			sz[v]+=sz[u];
		}
		return 1;
	}
}
int n,m;
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++) par[i]=i;
	int sl=n;
	int maxx=1;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		if(add(u, v) == 1){
			maxx=max(maxx,max(sz[find(u)],sz[find(v)]));
			sl--;
		}
		cout << sl << " " << maxx << "\n";
		
	}
	return 0;
}
