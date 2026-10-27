#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> adj[100005];
int dp[100005][2];
const int mod=1e9+7;
void dfs(int u, int v){
	dp[u][0]=1;
	dp[u][1]=1;
	for(auto i : adj[u]){
		if(i==v) continue;
		dfs(i,u);
		dp[u][0]=(dp[u][0]*dp[i][1])%mod;
		dp[u][1]=(dp[u][1]*(dp[i][0]+dp[i][1]))%mod;
	}
}
signed main(){
	int n; cin>> n;
	for(int i=1;i<=n-1;i++){
		int l,r; cin >> l >> r;
		adj[l].push_back(r);
		adj[r].push_back(l);
	}
	dfs(1,0);
	cout << (dp[1][0]+dp[1][1])%mod;
}
