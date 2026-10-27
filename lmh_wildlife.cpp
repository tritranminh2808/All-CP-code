#include <bits/stdc++.h>
using namespace std;
priority_queue <pair <int ,int > , vector <pair<int, int > > , greater <pair <int, int > > >pq;
struct pl{
	int first,second,ind;
};
struct cmp{
	bool operator ()(pl &a,pl &b){
		return a.first>b.first;
	}
};
vector < pl > adj[200005];
int kc[200005],a[200005];
bool vst[200005];
vector <pair <int, int > > t(200005);
void dijkstra(int u){
	kc[u]=0;
	pq.push({0,u});
	while(!pq.empty()){
		pair <int , int > p=pq.top();
		pq.pop();
// 		if(vst[p.second]) continue;
		if(kc[p.second]<p.first) continue;
// 		vst[p.second]=1;
		for(auto i:adj[p.second]){
			if(max(kc[p.second],i.second)<kc[i.first]){
				kc[i.first]=max(kc[p.second],i.second);
				pq.push({kc[i.first],i.first});
				t[i.first].first=p.second;
				t[i.first].second=i.ind;
			}
		}
	}
}
vector<int> trace_path(int S, int u) {
    vector<int> path;
    while (u != S) { 
        path.push_back(t[u].second);
        u=t[u].first;
    }
    reverse(path.begin(), path.end()); 
    return path;
}
int n,m;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<=200000;++i) t[i].first=-1;
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		kc[i]=INT_MAX;
	}
//	unordered_map<long long ,int > mm;
	int id=1;
	while(m--){
		int u,v; cin >> v >> u;
		adj[u].push_back({v,abs(a[u]-a[v]),id});
		adj[v].push_back({u,abs(a[u]-a[v]),id});
		id++;
	}
	dijkstra(1);
	cout << kc[n] << "\n";
	vector <pair<int ,int > > mp;
	vector <int> ss=trace_path(1,n);
	for(auto i: ss) cout << i << " ";
	return 0;
}

