#include <bits/stdc++.h>
//#define int long long
using namespace std;
vector <int> sol;
int vst[200005];
int par[200005];
vector <int> adj[200005];
int start=0,ed=0;
bool check=false;
bool dfs(int i){
	vst[i]=1;
	for(auto j: adj[i]){
		if(vst[j]==0){
			par[j]=i;
			if(dfs(j)) return true;
		}
		else if(vst[j]==1){
			start=j;
			ed=i;
			return true;
		}
	}
	vst[i]=2;
	return false;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
//		cung[{u,v}]=i+1;
	}
	for(int i=1;i<=n;i++){
		if(!vst[i]&&dfs(i)){
				vector <int> trace;
				int x=ed;
				while(1){
					trace.push_back(x);
					if(x==start) break;
					x=par[x];
				}
//				trace.push_back(start);
				reverse(trace.begin(),trace.end());
//				cout << "YES\n";
				cout << trace.size()+1 << "\n";
				for(auto j:trace) cout << j << " "; 
				cout << start;
				return 0;
		}
	}
	cout << "IMPOSSIBLE";
}
