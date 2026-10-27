#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
//#define int long long
using namespace std;
int n,q;
vector <int > adj[200005];
int dep[200005],jump[200005][20];
int timer=0;
vector <int> euler;
int sz;
bool exist[200005];
int pos[200005];
void dfs(int u,int v){
    pos[u]=++timer;
    euler.push_back(u);
	for(auto i:adj[u]){
		if(i==v) continue;
		dep[i]=dep[u]+1;
		jump[i][0]=u;
		dfs(i,u);
	}
}
void build(){
	for(int j=1;j<=18;j++) for(int i=1;i<=n;i++) jump[i][j]=jump[jump[i][j-1]][j-1];
}
int lca(int u, int v){
	if(dep[u]>dep[v]) swap(u,v);
	int dist=dep[v]-dep[u];
	for(int i=18;i>=0;i--){
		if(dist>= (1<<i)){
			dist-=(1<<i);
			v=jump[v][i];
		}
	}
	if(u==v) return u;
	for(int i=18;i>=0;--i){
		if(jump[v][i]==0||jump[u][i]==0) continue;
		if(jump[u][i]!=jump[v][i]){
			u=jump[u][i];
			v=jump[v][i];
		}
	}
	return jump[u][0];
}
vector <int>  fi[200005];
bool cmp(int a, int b){
    return pos[a]<pos[b];
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
 	for(int i=1;i<n;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
    build();
	while(q--){
		int m; cin >> m;
		vector <int> v(m);
		for(int i=0;i<m;i++) cin >> v[i];
        sort(v.begin(),v.end(),cmp);
        int sol=0;
		for(int i=0;i<m;i++)  sol+=dep[v[i]]+dep[v[(i+1)%m]]-2*dep[lca(v[i],v[(i+1)%m])];
        
        cout << sol/2 << "\n";
	}
	return 0;
}
