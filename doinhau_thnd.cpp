#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
vector <pair <int, int > > adj[1005];
int dep[1005],high[1005],jump[1005][11];

void dfs(int u,int v){
	for(auto i:adj[u]){
		if(i.first==v) continue;
		high[i.first]=high[u]+i.second;
		dep[i.first]=dep[u]+1;
		jump[i.first][0]=u;
		dfs(i.first,u);
	
	}
}
void build(){
	for(int j=1;j<=10;j++) for(int i=1;i<=n;i++) jump[i][j]=jump[jump[i][j-1]][j-1];
}
int lca(int u, int v){
	if(dep[u]>dep[v]) swap(u,v);
	int dist=dep[v]-dep[u];
	for(int i=10;i>=0;i--){
		if(dist>= (1<<i)){
			dist-=(1<<i);
			v=jump[v][i];
		}
	}
	if(u==v) return u;
	for(int i=10;i>=0;--i){
		if(jump[v][i]==0||jump[u][i]==0) continue;
		if(jump[u][i]!=jump[v][i]){
			u=jump[u][i];
			v=jump[v][i];
		}
	}
	return jump[u][0];
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
//	dijkstra(1);
	dfs(1,0);
	build();
	long double sol=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(__gcd(i,j)==1) {
				sol+=(high[i]+high[j]-2*high[lca(i,j)])*2;
				cnt+=2;
			}
		}
	}
	cout << fixed << setprecision(4) << sol/cnt;
	return 0;
}
