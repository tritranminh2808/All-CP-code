#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue <pair <int ,int > , vector <pair<int, int > > , greater <pair <int, int > > >pq;
vector < pair <int , int > > adj[500005];
int kc[500005],a[500005];
vector <int> t(500005,-1);
void dijkstra(int u){
	kc[u]=0;
	pq.push({0,u});
	while(!pq.empty()){
		pair <int , int > p=pq.top();
		pq.pop();
		if(kc[p.second]<p.first) continue;
		for(auto i:adj[p.second]){
			if(max(kc[p.second],i.second)<kc[i.first]){
				kc[i.first]=max(kc[p.second],i.second);
				pq.push({kc[i.first],i.first});
				t[i.first]=p.second;
				
			}
		}
	}
}
vector<int> trace_path(int S, int u) {
    vector<int> path;
    while (u != -1) { 
        path.push_back(u);
        u=t[u];
    }
    reverse(path.begin(), path.end()); 
    return path;
}
int n,m;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		kc[i]=1e18;
	}
	unordered_map<long long,int > mm;
	int id=1;
	for(int i=1;i<=m;i++){
		int u,v; cin >> u >> v;
		adj[u].push_back({v,i});
	}
	dijkstra(1);
	cout << kc[n] ;
	return 0;
}
