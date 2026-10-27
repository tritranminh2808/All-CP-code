#include <bits/stdc++.h>
using namespace std;
vector <int > adj[200005],trace;
int n,m;
int vst[200005];
int cnt[200005],par[200005];
bool dfs(int u){
//	cout << u << " ";
	vst[u]=1;
	for(int i:adj[u]){
		if(!vst[i]){
			par[i]=u;
			dfs(i);
		}
		else{
			trace.push_back(i);
			int cur=u;
			while(cur!=i){
				trace.push_back(cur);
				cur=par[cur];
			}
			trace.push_back(i);
			reverse(trace.begin(),trace.end());
			cout << trace.size() << "\n";
			for(auto z:trace) cout << z << " ";
			exit(0);
		}
	}

}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(m--){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
//		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++) {
		if(!vst[i]) dfs(i);
	}
	cout  << "IMPOSSIBLE";
}
