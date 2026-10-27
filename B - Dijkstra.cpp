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
   // cout << u << endl;
        path.push_back(u);
        u = t[u];
    }
    reverse(path.begin(), path.end()); 

    return path;
}
signed main(){
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i) kc[i]=1e16;
	for(int i=1;i<=m;i++){
		int a,b,c; cin >>a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dijkstra(1);
//	cout << 1 << " ";
	for(auto i : trace_path(1,n)) cout << i << " ";
}
