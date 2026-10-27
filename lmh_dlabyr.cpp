#include <bits/stdc++.h>
using namespace std;
vector <int> adj[200005];
bool loc[200005];
int t=0,chk=0;
bool vst[505];
void dfs(int u){
	if(u==t&&!chk){
		cout << "Y";
		chk=1;
		return;
	}
	if(vst[u]||chk) return;
	vst[u]=1;
	for(auto i:adj[u]) {
		if(loc[i]) dfs(i);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	while(m--){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
//		adj[v].push_back(u);
	}
	while(k--){
		char q; cin >> q;
		if(q=='X'){
			int u; cin >> u;
			loc[u]=1;
		}
		else{
			int s,l; cin >> s >> l;
			if(!loc[s]) {
				cout << "N";
				continue;
			}
			if(s==l){
				cout << "Y";
				continue;
			}
			t=l;
			chk=0;
			for(int i=1;i<=n;++i) vst[i]=0;
			dfs(s);
			if(!chk) cout << "N";
		}
	}
	return 0;
}
