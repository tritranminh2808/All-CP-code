#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
int par[p],par2[p];
vector <int> sz(p,1),sz2(p,1);
int find(int u){
	if(par[u]==u) return u;
	else {
		par[u]=find(par[u]);
		return par[u];
	}
}
int find2(int u){
	if(par2[u]==u) return u;
	else {
		par2[u]=find2(par2[u]);
		return par2[u];
	}
}
void add(int u, int v){
	u=find(u);v=find(v);
	if(u!=v) {
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
void add2(int u, int v){
	u=find2(u);v=find2(v);
	if(u!=v) {
		if(sz2[u]>=sz2[v]) {
			par2[v]=u;
			sz2[u]+=sz2[v];
		}
		else {
			par2[u]=v;
			sz2[v]+=sz2[u];
		}
	}
}
int a,n,m;
int main()
{
	cin >> a>>n >> m;
	for(int i=1;i<=a;i++) {
		par[i]=i;par2[i]=i;
	}
	int sl=n;
	int maxx=1;
	for(int i=0;i<n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		add2(u,v);
	}
	vector <pair < int, int> > vt;
	int ss=0;
	for(int i=1;i<a;i++){
		for(int j=i+1;j<=a;j++){
			if(find(i)!=find(j)&&find2(i)!=find2(j)){
				ss++;
				vt.push_back({i,j});
				add(i,j);add2(i,j);
			}
		}
	}
	cout << ss << "\n";
	for(int i=0;i<vt.size();i++) cout<< vt[i].first << " " << vt[i].second << "\n";
	return 0;
}
