#include <bits/stdc++.h>
using namespace std;
long long adj[100005];
vector <int > par [100005];
void dfs(int cha, long long lu){
	for(auto i : par[cha]){
		adj[i]+=lu;
		dfs(i,lu);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n >> m;
	long long mot; cin >> mot;
	adj[1]=mot;
	for(int i=2;i<=n;i++){
		long long luong, cha; cin >> luong >> cha;
		par[cha].push_back(i);
		adj[i]=luong;
	}
	while(m--){
		char c; cin >> c;
		if(c=='p'){
			long long cha, tang; cin >> cha >> tang;
			dfs(cha,tang);
		}
		else{
			int u; cin>> u; cout << adj[u] << "\n";
		}
	}
	return 0;
}

