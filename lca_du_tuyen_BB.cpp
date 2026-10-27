#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
//#define int long long
using namespace std;
int n; 
vector <int > adj[200005];
int dep[200005],stt[200005],ed[200005],jump[200005][20];
int timer=0;
vector <int> euler;
int sz;
void dfs(int u,int v){
	stt[u]=++timer;
	euler.push_back(u);
	for(auto i:adj[u]){
		if(i==v) continue;
		dep[i]=dep[u]+1;
		jump[i][0]=u;
		dfs(i,u);
	}
	ed[u]=timer;
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
int pos[200005];
void reset(){
    for(int i=1;i<=n;i++) adj[i].clear();
    euler.clear();
    timer=0;
    memset(dep,0,sizeof(dep));
    memset(stt,0,sizeof(stt));
    memset(ed,0,sizeof(ed));
    memset(jump,0,sizeof(jump));
    memset(pos,0,sizeof(pos));
}
void cok(){
    for(int i=1;i<n;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    dfs(1,0);
    build();
    for(int i=0;i<euler.size();i++) pos[euler[i]]=i+1;
    int q; cin >> q;
    int root=1;
    while(q--){
        char c; cin >> c;
        if(c=='?'){
            int u,v; cin >> u >> v;
            if(pos[u]>=stt[root]&&pos[u]<=ed[root]&&pos[v]<=ed[root]&&pos[v]>=stt[root]) cout << lca(u,v) << "\n";
            else if(pos[u]>=stt[root]&&pos[u]<=ed[root]&&(pos[v]>ed[root]||pos[v]<stt[root])) cout << root << "\n";
            else if(pos[v]>=stt[root]&&pos[v]<=ed[root]&&(pos[u]>ed[root]||pos[u]<stt[root])) cout << root << "\n";
            else if((pos[u]>ed[root]||pos[u]<stt[root])&&(pos[v]>ed[root]||pos[v]<stt[root])){
                int k1=lca(root,u),k2=lca(root,v),k3=lca(u,v);
                if(dep[k1]>dep[k2]&&dep[k1]>dep[k3]) cout << k1 << "\n";
                else if(dep[k2]>dep[k1]&&dep[k2]>dep[k3]) cout << k2 << "\n";
                else cout << k3 << "\n";
            }
        }
        else{
            int r; cin >> r;
            root=r;
            continue;
        }
    }
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while(cin >> n){

        if(n==0) exit(0);
        reset();
        cok();
    }
	return 0;
}
