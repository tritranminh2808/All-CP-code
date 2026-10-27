#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,root;
vector <pair <int, int> > adj[200005];
int dep[200005],high[200005],jump[200005][18];
int dp[200005],dp2[18][200005];	
vector<pair <int, int > > edge;
bool shop[200005];
void dfs(int u,int v){
    if(shop[u]) dp[u]=0;
	for(auto i:adj[u]){
		if(i.first==v) continue;
//		high[i.first]=high[u]+i.second;
		dep[i.first]=dep[u]+1;
        high[i.first]=high[u]+i.second;
		jump[i.first][0]=u;
		dfs(i.first,u);
        if(!shop[u]) dp[u]=min(dp[u],dp[i.first]+i.second);
	}
}
int mn[200005][20];
void build(){
	for(int j=1;j<=17;j++) for(int i=1;i<=n;i++) jump[i][j]=jump[jump[i][j-1]][j-1];
    for(int j=1;j<=17;j++){
        for(int i=1;i<=n;i++){
            if(jump[i][j-1]) mn[i][j] = min(mn[i][j-1], mn[jump[i][j-1]][j-1]);
        }
    }
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
int val[200005];
int find(int u, int v){
    if(dep[u]<dep[v]) return 1e18;
    int res=1e18;
    int cur=u;
    int dist = dep[u]-dep[v];
    for(int k=0;k<=17;k++){
        if(dist & (1<<k)){
            res = min(res,mn[cur][k]);
            cur = jump[cur][k];
            if(cur==0) break;
        }
    }
    if(cur) res = min(res,val[cur]);
    return res;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q >> root;
    for(int i=1;i<n;i++){
        int u,v,w; cin>> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});   
        edge.push_back({u,v});
    }
    
    for(int i=0;i<m;i++){
        int x;cin >> x;
        shop[x]=1;
    }
    for(int i=1;i<=n;i++) {
        dp[i]=1e18;
    }
    dfs(root,0);
    for(int k=0;k<18;k++)  for(int i=1;i<=n;i++) mn[i][k]=1e18;
        
    for(int v=1; v<=n; ++v){
        if(dp[v] >=1e18/2) val[v]=1e18;
        else val[v]=dp[v]-high[v];
        mn[v][0]=val[v]; 
    }
    // dfs2(root,0);
    build();
    while(q--){
        int i,r; cin >> i >> r;
        i--;
        int u =edge[i].first,v=edge[i].second;
        if(dep[u]<dep[v]) swap(u,v); 
        if(lca(u,r)!=u) {
            cout << "escaped\n";
            continue;
        }
        if(dp[u]==1e18) {
            cout << "oo\n";
            continue;
        }
        int x=find(r,u);
        cout << x+high[r] << "\n";

    }
	return 0;
}
