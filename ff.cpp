#include <bits/stdc++.h>
using namespace std;
set <int> adj[200005];
int n,m;
set <int> st;
multiset <int> sol;
bool vst[200005];
queue<int> q;
void bfs(int u){
	vst[u]=1;
	int sz=1;
	q.push(u);
	st.erase(u);
	vector <int> del;
	while(!q.empty()){
		int j=q.front();
		q.pop();
		for(auto it:st){
			if(adj[j].count(it)==0){
				q.push(it);
				sz++;
				del.push_back(it);
				vst[it]=1;
			}
		}
		for(auto i: del) st.erase(i);
		del.clear();
	}
	
	sol.insert(sz);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("CONNECT.INP","r",stdin);
//	freopen("CONNECT.OUT","w",stdout);
	cin >> n >> m;
	while(m--){
		int u,v; cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for(int i=1;i<=n;i++) st.insert(i);
	for(int i=1;i<=n;i++){
		if(!vst[i]) bfs(i);
	}
	cout << sol.size() << "\n";
	for(auto i:sol) cout << i << " ";
	return 0;
}
