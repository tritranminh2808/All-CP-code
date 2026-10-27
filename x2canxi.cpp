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

vector<int> trace(int S, int u) {
    if (u != S && t[u] == -1) return vector<int>(1, -1); 
    vector<int> path;
    while (u != -1) { 
        path.push_back(u);
        u=t[u];
    }
    reverse(path.begin(), path.end()); 
    return path;
}
vector <pair <int, int> > vv;
signed main(){
	map<pair <int, int > , int> mp;
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i) kc[i]=1e16;
	for(int i=1;i<=m;i++){
		int a,b,c; cin >>a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
		vv.push_back({a,b});
	}
	dijkstra(1);
	int goc=kc[n];
	int sol=0;
	for(int i=0;i<m;i++){
		for(int i=1;i<=n;++i) kc[i]=1e16;
		int a=vv[i].first,b=vv[i].second;
		int ida=0,idb=0;
		for(int j=0;j<adj[a].size();j++){
			if(adj[a][j].first==b){
				adj[a][j].second*=2;
				ida=j;
				break;
			}
		}
		for(int j=0;j<adj[b].size();j++){
			if(adj[b][j].first==a){
				adj[b][j].second*=2;
				idb=j;
				break;
			}
		}
		dijkstra(1);
		sol=max(sol,kc[n]-goc);
		adj[a][ida].second/=2;
		adj[b][idb].second/=2;
	}
	cout << sol;
	return 0;
}
