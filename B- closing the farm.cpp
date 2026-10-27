#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
int par[p];
vector <int> sz(p,1);
int find(int u){
	if(par[u]==u) return u;
	else {
		par[u]=find(par[u]);
		return par[u];
	}
}
int cnt=0;
void add(int u, int v){
	u=find(u);v=find(v);
	if(u==v) return;
		if(sz[u]>=sz[v]) {
			par[v]=u;
			sz[u]+=sz[v];
		}
		else {
			par[u]=v;
			sz[v]+=sz[u];
		}
	cnt--;
}
int n,m;
vector <int> adj[200005];
bool check[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) par[i]=i;
	for(int i=1;i<=m;i++){
		int u,v; cin>> u >> v;
		adj[u].push_back(v);
        adj[v].push_back(u);
	}
    vector <int> hv(n+1),ans(n+1);
    for(int i=1;i<=n;i++) cin >> hv[i];
    for(int i=n;i>=1;i--){
        check[hv[i]]=1;
        cnt++;
        for(auto j:adj[hv[i]]) if(check[j]) add(hv[i],j);
        if(cnt==1) ans[i]=1;
        else ans[i]=0;
    }
    for(int i=1;i<=n;i++) {
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
	return 0;
}
