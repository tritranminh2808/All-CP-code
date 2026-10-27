#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
int par[p];
vector <int> sz(p,1);
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
int main()
{
//	freopen("CONNECT.INP","r",stdin);
//	freopen("CONNECT.OUT","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) par[i]=i;
	int sl=n;
	int maxx=1;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		
	}
	for(int i=1;i<=n;i++){
		if(check[find(i)]==0){
			for(int j=1;j<=n;j++){
				if(find(j)==find(i)) cout << j << " ";
			}
			check[find(i)]=1;
			cout << "\n";
		}
	}
	return 0;
}
