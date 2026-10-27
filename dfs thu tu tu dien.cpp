#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
set<int> adj[1000005];
bool vst[100005];
int par[100005];
void dfs(int u){
	vst[u]=1;
	if(u==t){
		int x=u;
		vector <int> trace;
		while(x!=-1){
			trace.push_back(x);
			x=par[x];
		}
		reverse(trace.begin(),trace.end());
		for(auto i:trace) cout << i << ' ';
		exit(0);
	}
	for(auto i:adj[u]){
		if(!vst[i]) {
			par[i]=u;
			dfs(i);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	for(int i=0;i<=n;++i) par[i]=-1;
	while(m--){
		int a,b; cin >> a >> b;
		adj[a].insert(b);
	}
	dfs(s);
	return 0;
}
