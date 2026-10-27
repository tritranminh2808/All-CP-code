#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
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
int sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) par[i]=i;
	while(m--){
		int u,v; cin >> u >> v;
		add(u,v);
	}
	for(int i=1;i<=n;i++) minn[i]=1e18;
	for(int i=1;i<=n;i++){
		int u=find(i);
		if(a[i]<minn[u]) minn[u]=a[i];
	}
	vector <int> cnt;
	for(int i=1;i<=n;i++) if(find(i)==i) cnt.push_back(minn[i]);
	if(cnt.size()<=1){
		cout << 0;
		return 0;
	}
	sort(cnt.begin(),cnt.end());
	for(auto i: cnt) sol+=i;
	sol+=(cnt.size()-2)*cnt[0];
	cout << sol;
	return 0;
}
