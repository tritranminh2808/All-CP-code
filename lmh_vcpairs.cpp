#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
//int cc1=INT_MAX;
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
void nen(){
	vector <int> b;
	for(int i=1;i<=n;i++) b.push_back(a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	unordered_map<long long ,int > mp;
	for(int i=0;i<b.size();i++) mp[b[i]]=i;
	for(int i=1;i<=n;i++) a[i]=mp[a[i]];
}
unordered_map<int, int > cnt[100005];
int sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
//	nen();
	for(int i=1;i<=n;i++) {
		par[i]=i;
		cnt[i][a[i]]++;
	}
	while(m--){
		int x,y; cin >> x >> y;
		if(find(x)!=find(y)){
			x=find(x);
			y=find(y);
			if(sz[x]<sz[y]) swap(x,y);
			for(auto i:cnt[y]){
				sol+=cnt[x][i.first]*i.second;
				cnt[x][i.first]+=i.second;
			}
			cnt[y].clear();
			add(x,y);
		}
		cout << sol << "\n";
	}
	return 0;
}
