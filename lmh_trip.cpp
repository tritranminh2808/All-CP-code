#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n,m;
vector <int> adj[200005];
int dep[200005],jump[200005][18];
int cnt[200005];	
int num[200005],timer=0;
void dfs(int u,int v){
    num[u]=++timer;
	for(auto i:adj[u]){
		if(i==v) continue;
//		high[i.first]=high[u]+i.second;
		dep[i]=dep[u]+1;
		jump[i][0]=u;
		dfs(i,u);
	}
}
void build(){
	for(int j=1;j<=17;j++) for(int i=1;i<=n;i++) jump[i][j]=jump[jump[i][j-1]][j-1];
}
int lca(int u, int v){
	if(dep[u]>dep[v]) swap(u,v);
	int dist=dep[v]-dep[u];
	for(int i=17;i>=0;i--){
		if(dist>= (1<<i)){
			dist-=(1<<i);
			v=jump[v][i];
		}
	}
	if(u==v) return u;
	for(int i=17;i>=0;--i){
		if(jump[v][i]==0||jump[u][i]==0) continue;
		if(jump[u][i]!=jump[v][i]){
			u=jump[u][i];
			v=jump[v][i];
		}
	}
	return jump[u][0];
}
bool cmp(int a, int b){
    return num[a]<num[b];
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b,c; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
//	dijkstra(1);
	dfs(1,0);
	build();
    for(int i=1;i<=n;i++){
        vector <int> v;
        for(int j=0;j<=n;j+=i) v.push_back(j);
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(int i=1;i<v.size();i++) ans+=dep[v[i]]+dep[v[i-1]]-2*dep[lca(v[i],v[i-1])];
        ans+=dep[v.back()];
        cout << ans << "\n";
    }
	return 0;
}
