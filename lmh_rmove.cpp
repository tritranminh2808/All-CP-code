#include <bits/stdc++.h>
//#define int long long
using namespace std;
vector <int > adj[5005];
int n,m;
struct pl{
	int l,r,cnt;
};
void bfs(){
	map<pair<int, int >, bool> vst;
	queue<pl> q;
	q.push({1,n,0});
	while(!q.empty()){
		pl p=q.front();
//		cout << p.l << ' ' << p.r << "\n";
		q.pop();
		if(p.l==p.r){
			cout<< p.cnt;
			return;
		}
		if(vst[{p.l,p.r}]||vst[{p.r,p.l}]) continue;
		vst[{p.l,p.r}]=1;
		vst[{p.r,p.l}]=1;
		for(auto i:adj[p.l]){
			for(auto j:adj[p.r]) q.push({i,j,p.cnt+1});
		}
	}
	cout << -1;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	while(m--){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
	}
	bfs();
}
