#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
//#define int long long
using namespace std;
int n,q;
vector <int > adj[100005];
int dep[100005],jump[15][10005];
int timer=0;
vector <int> euler;
int sz;
void dfs(int u,int v){
	for(auto i:adj[u]){
		if(i==v) continue;
		dep[i]=dep[u]+1;
		jump[0][i]=u;
		dfs(i,u);
	}
}
bool vst[10005];
void build_euler(int i){
	vst[i]=1;
	euler.push_back(i);
	for(auto j:adj[i]){
		if(!vst[j]) {
			build_euler(j);
			euler.push_back(i);
		}
	}
}
vector <int> coconut[100005];
int mau[100005];
pair <int, int> e[200005],st[18][20005];
void build_rmq(){
	for(int i=1;i<=sz;i++) st[0][i]=e[i];
	for(int i=1;i<=17;i++){
		for(int j=1;j+(1<<i)-1<=sz;j++){
			if(st[i-1][j].second < st[i-1][j+(1<<i-1)].second) st[i][j]=st[i-1][j];
			else st[i][j]=st[i-1][j+(1<<i-1)];
		}
	}
}
int find(int l, int r){
	if(l>r) swap(l,r); 
	int k=__lg(r-l+1);
	if(st[k][l].second<st[k][r-(1<<k)+1].second) return st[k][l].first;
	return st[k][r-(1<<k)+1].first;
}
int fi[10005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	euler.push_back(0);
	build_euler(1);
	sz=euler.size()-1;
	// for(auto i:euler) cout << i << " ";
//	build();
	int quadua=0;
	cin >> quadua;
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		mau[i]=x;
		coconut[x].push_back(i);
	}
	for(int i=1;i<=sz;i++) {
		e[i]={euler[i],dep[euler[i]]};
		if(fi[euler[i]]==0) fi[euler[i]]=i;
	}
//	for(int i=0;i<)
	build_rmq();
	cin >> q;
//	cout << find(fi[3],fi[2]);
	while(q--){
		int u,v; cin >> u >> v;
//		cout << find(u,v) << " " << lca(u,v) << "\n";
		if(mau[u]==v){
			cout << "0\n";
			continue;
		}
		if(mau[jump[0][u]]==v){
			cout << "1\n";
			continue;
		}
		int minn=INT_MAX;
		for(auto i:coconut[v]) minn=min(minn,dep[u]+dep[i]-2*dep[find(fi[u],fi[i])]);
		cout << minn << "\n";
	}
	return 0;
}
