#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
vector <pair < int, int > >   adj[1000005];
int kc[1000005];
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
			}
		}
	}
}
int road[505][505];
vector <int> qu[505];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin >> n >> m >> q;
//	m=n-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) road[i][j]=-1;
	}
	for(int i=1;i<=m;i++){
		int a,b,c; cin>> a >> b >>c ;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	set<int> st;
	vector <pair <int, int > > qq;
	while(q--){
		int u,v; cin >> u >> v;
		qq.push_back({u,v});
		st.insert(u);
		qu[u].push_back(v);
	}
	for(auto i:st){
		bool check=0;
		for(auto j:qu[i]){
			if(road[i][j]==-1) {
				check=1;
				break;
			}
		}
		if(!check) continue;
		for(int i=1;i<=n;++i) kc[i]=1e18;
		dijkstra(i);
		for(auto j:qu[i]){
			road[i][j]=kc[j];
			road[j][i]=kc[j];
		}
	}
	for(auto i:qq){
		if(road[i.first][i.second]==1e18) cout << -1 << "\n";
		else cout << road[i.first][i.second] << "\n";
	}
}
