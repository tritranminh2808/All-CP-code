#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct pl{
	int x,y,w,id;
};
pl edge[200005];
int par[200005],sz[200005];
int find(int x){
	if(par[x]==x) return x;
	par[x]=find(par[x]);
	return par[x];
}
void add(int x, int y){
	x=find(x);y=find(y);
	if(x==y) return;
	if(sz[x]>sz[y]){
		par[y]=x;
		sz[x]+=sz[y];
		return;
	}
	par[x]=y;
	sz[y]+=sz[x];
}
bool cmp(pl a, pl b){
	return a.w<b.w;
}
vector <pair <int , int > > adj[200005];
vector <int> kruskal;
int dep[200005],jump[18][200005],maxx[18][200005];
void dfs(int u,int v){
	for(auto i:adj[u]){
		if(i.first==v) continue;
		dep[i.first]=dep[u]+1;
		jump[0][i.first]=u;
		maxx[0][i.first]=i.second;
		dfs(i.first,u);
	}
}
void build(){
	for(int i=1;i<=17;i++){
		for(int j=1;j<=n;j++) {
			jump[i][j]=jump[i-1][jump[i-1][j]];
			maxx[i][j]=max(maxx[i-1][j],maxx[i-1][jump[i-1][j]]);
		}
	}
}
int find(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	int dist=dep[v]-dep[u];
	int cc=0;
	for(int i=17;i>=0;i--){
		if(dist>=(1<<i)){
			dist-=(1<<i);
			cc=max(cc,maxx[i][v]);
			v=jump[i][v];
		}
	}
	if(u==v) return cc;
	for(int i=17;i>=0;i--){
		if(jump[i][u]==0||jump[i][v]==0) continue;
		if(jump[i][u]!=jump[i][v]){
			cc=max({cc,maxx[i][u],maxx[i][v]});
			u=jump[i][u];
			v=jump[i][v];
		}
	}
	return max({cc,maxx[0][u],maxx[0][v]});
}
bool chk[200005];
int sol[200005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		par[i]=i;
		sz[i]=1;
	}
	for(int i=0;i<m;i++) {
		cin >> edge[i].x >> edge[i].y>> edge[i].w;
		edge[i].id=i;
		
	}
	sort(edge,edge+m,cmp);
	int S=0;
	
	for(int i=0;i<m;i++){
		int u=find(edge[i].x),v=find(edge[i].y);
		if(u==v) continue;
		add(u,v);
		S+=edge[i].w;
		adj[edge[i].x].push_back({edge[i].y,edge[i].w});
		adj[edge[i].y].push_back({edge[i].x,edge[i].w});
		chk[i]=1;
	}
	dfs(1,0);
	build();
	for(int i=0;i<m;i++){
		if(chk[i]) {
			sol[edge[i].id]=S;
			continue;
		} 
		sol[edge[i].id]=-find(edge[i].x,edge[i].y)+S+edge[i].w;
	}
	for(int i=0;i<m;i++) cout << sol[i] << "\n";
	return 0;
}
