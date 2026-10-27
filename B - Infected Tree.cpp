#include <bits/stdc++.h>
using namespace std;
vector <int> adj[300005],sz(300005),dp(300005);
void size(int u, int v){
	sz[u]=1;
	for(auto i : adj[u]){
		if(i==v) continue;
		size(i,u);
		sz[u]+=sz[i];
	}
	
}
void dfs(int u, int v){
	int node1=0,node2=0;
	for(auto i : adj[u]){
		if(i==v) continue;
		dfs(i,u);
		if(node1==0) node1=i;
		else node2=i;
	}
	if(node1==0) return ;
	if(node2==0) {
		dp[u]=sz[node1]-1;return;
	}
	dp[u]=max(sz[node1]-1+dp[node2],sz[node2]-1+dp[node1]);
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
	
		int n; cin>> n;
		for(int i=0;i<n+2;++i){
			adj[i].clear();
			sz[i] = 0;
			dp[i] = 0;
		}
		for(int i=1;i<=n-1;i++){
			int l,r; cin >> l >> r;
			adj[l].push_back(r);
			adj[r].push_back(l);
		}
		size(1,0);
		
		dfs(1,0);
		
		//cout << "\n";
		cout << dp[1] <<"\n";
	}
	
}
