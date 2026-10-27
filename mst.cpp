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
struct pl{
	int w,a,b,id;
};
pl sech[200005];
bool cmp(pl x, pl y){
	return x.w<y.w;
}
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
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		sech[i]={w,u,v,i};
//		add(u,v);
	}
	sort(sech,sech+m,cmp);
	vector <bool> sol(200005);
	int i=0,j=0;
	while(i<m){
		j=i;
		while(j<m&&sech[i].w==sech[j].w) j++;
		for(int k=i;k<j;k++){
			if(find(sech[k].a)!=find(sech[k].b)) sol[sech[k].id]=1;
			else sol[sech[k].id]=0;
		}
		for(int k=i;k<j;k++) add(sech[k].a,sech[k].b);
		i=j;
	}
	for(int i=0;i<m;i++){
		if(sol[i]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
