#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
vector <pair <int, int > > adj[200005];
int dep[200005],high[2005],jump[200005][18],minn[200005][18],maxx[200005][18];

void dfs(int u,int v){
	for(auto i:adj[u]){
		if(i.first==v) continue;
		minn[i.first][0]=min(minn[i.first][0],i.second);
		maxx[i.first][0]=max(maxx[i.first][0],i.second);
		dep[i.first]=dep[u]+1;
//		high[i]
		jump[i.first][0]=u;
		dfs(i.first,u);
	}
}
void build(){
	for(int j=1;j<=17;j++) {
		for(int i=1;i<=n;i++) {
			jump[i][j]=jump[jump[i][j-1]][j-1];
			minn[i][j]=min(minn[i][j-1],minn[jump[i][j-1]][j-1]);
			maxx[i][j]=max(maxx[i][j-1],maxx[jump[i][j-1]][j-1]);
		}
	}
}
pair <int, int >  find(int u, int v){
	if(dep[u]>dep[v]) swap(u,v);
	int minx=1e16,maxn=0;
	int dist=dep[v]-dep[u];
	for(int i=17;i>=0;i--){
		if(dist>= (1<<i)){
			dist-=(1<<i);
			minx=min(minx,minn[v][i]);
			maxn=max(maxn,maxx[v][i]);
			v=jump[v][i];
		}
	}
	if(u==v) return {minx,maxn};
	for(int i=17;i>=0;--i){
//		if(jump[v][i]==0||jump[u][i]==0) continue;
		if(jump[u][i]!=jump[v][i]){
			minx=min({minx,minn[u][i],minn[v][i]});
			maxn=max({maxn,maxx[v][i],maxx[u][i]});
			u=jump[u][i];
			v=jump[v][i];
		}
	}
	minx=min({minx,minn[u][0],minn[v][0]});
	maxn=max({maxn,maxx[u][0],maxx[v][0]});
	return {minx,maxn};
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i=0;i<=n;i++){
    	for(int j=0;j<=17;j++){
        	minn[i][j]=1e16;
			maxx[i][j]=0;
			jump[i][j]=0;
		}
	}
	for(int i=1;i<n;i++){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dep[1]=0;
	jump[1][0]=0;
	minn[1][0]=1e16;
	maxx[1][0]=0;
	dfs(1,0);
	build();
	while(q--){
		int l,r; cin >> l >> r;
		cout  << find(l,r).second<< "\n";
	}
	return 0;
}
