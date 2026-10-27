#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
vector <pair < int, int > >   adj[100005];
int kc[100005];
vector < int > t(100005,-1);
void dijkstra(int u)
{
	kc[u]=0;
	pq.push({kc[u],u});
	while(!pq.empty()){
		pair <int, int > p=pq.top();
		pq.pop();
		if(kc[p.second]<p.first) continue;
		for(auto i: adj[p.second]){
			if(p.first+i.second<kc[i.first]){
				kc[i.first]=p.first+i.second;
				pq.push({kc[i.first],i.first});
				t[i.first]=p.second;
			}
		}
	}
}

vector<int> trace_path(int S, int u) {
    if (u != S && t[u] == -1) return vector<int>(1, -1); 
    vector<int> path;
    while (u != -1) { 
        path.push_back(u);
        u=t[u];
    }
    reverse(path.begin(), path.end()); 
    return path;
}
bool vst[100005];
vector <int> par[100005];
vector <int> res;
bool cmp(int a, int b){
	return vst[a]<vst[b];
}
bool chk[100005];
//int cntt[100005];
void dfs(int u) {
    vst[u]=1;
    res.push_back(u);
    for (pair<int, int > i:adj[u]) {
    	int v=i.first,w=i.second;
        if (!vst[v]&&!chk[v]) {
            dfs(v);
            res.push_back(u);
        }
    }
    for (pair<int, int> i: adj[u]) {
    	int v=i.first,w=i.second;
        if (!vst[v]&&chk[v]) dfs(v);
    }
}
signed main(){
	
	int n,m;
	cin >> n;
	m=n-1;
	for(int i=1;i<=n;++i) kc[i]=1e18;
	int S=0;
	for(int i=1;i<=m;i++){
		int a,b,c; cin>> a >> b >>c ;
		S+=c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
		par[a].push_back(b);
		par[b].push_back(a);
//		cntt[a]++;
//		cntt[b]++;
	}
	dijkstra(1);
//	cout << kc[n];
	int maxx=0,cc;
	for(int i=1;i<=n;i++){
		if(kc[i]>maxx){
			maxx=kc[i];
			cc=i;
		}
	}
	vector <int> v=trace_path(1,cc);
	for(int i=0;i<v.size();i++) chk[v[i]]=1;
	cout << S*2-maxx << "\n";
//	for(int i=1;i<=n;i++) chk[i]=1;
	dfs(1);
	cout << res.size() << "\n";
	for(auto i:res) cout << i << " ";
//	while()?
}
