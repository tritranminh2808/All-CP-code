#include <bits/stdc++.h>
using namespace std ;
const int p=1e6+5;
int par[p];
vector <int> sz(p,1);
bool cmp(vector <int> a, vector <int> b){
	return a[2]<b[2];
}
int find(int u){
	if(u==par[u]) return u;
	else{
		par[u]=find(par[u]);
		return par[u];
	}
}
void add(int u, int v){
	u=find(u);
	v=find(v);
	if(u==v) return ;
	else{
		if(sz[u]>=sz[v]){
			par[v]=u;
			sz[u]+=sz[v];
		}
		else{
			par[u]=v;
			sz[v]+=sz[u];
		}
	}
}
int main(){
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++) par[i]=i;
	vector < vector <int> > vt(m);
	for(int i=0;i<m;i++){
		int a,b,c; cin >> a >> b >> c;
		vt[i].push_back(a);
		vt[i].push_back(b);
		vt[i].push_back(c);
	}
	int sol=-1;
	sort(vt.begin(),vt.end(),cmp);
	for(auto v:vt){
		if(find(v[0])!=find(v[1])) {
			add(v[0],v[1]);
			sol=max(sol,v[2]);
		}
	}
	cout << sol;
	return 0;
}
