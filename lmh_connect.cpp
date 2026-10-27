#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
int par[p];
int sz[p];
bool check[p];
int find(int u){
	if(par[u]==u) return u;
	else {
		par[u]=find(par[u]);
		return par[u];
	}
}
void add(int u, int v){
	u=find(u);v=find(v);
	if(u!=v)
		if(sz[u]>=sz[v]) {
			par[v]=u;
			sz[u]+=sz[v];
		}
		else {
			par[u]=v;
			sz[v]+=sz[u];
		}
	}
int n,m;
int lod[200005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("CONNECT.INP","r",stdin);
//	freopen("CONNECT.OUT","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		par[i]=i;
		sz[i]=1;
	}
	while(m--){
		int u,v;
		cin >> u >> v;
		add(u,v);
	}
	for(int i=1;i<=n;i++){
		lod[i]=find(i);
	}
	unordered_map<int, vector <int > > mp;
	for(int i=1;i<=n;i++){
		mp[lod[i]].push_back(i);
	}
	for(auto i: mp){
		for(auto j:i.second) cout << j << " ";
		cout << "\n";
	}
	return 0;
}
