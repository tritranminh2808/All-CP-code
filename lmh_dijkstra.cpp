#include <bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue < pair <ll, int > , vector < pair <ll, int > > , greater<pair <ll, int > > > pq;
vector <pair <ll, int > >   adj[1000005];
ll kc[1000005];
void dijkstra(int u)
{
	kc[u]=0;
	pq.push({kc[u],u});
	while(!pq.empty()){
		pair <ll, int > p=pq.top();
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
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
//	m=n-1;
	for(int i=1;i<=n;++i) kc[i]=1e18;
	for(int i=1;i<=m;i++){
		int a,b,c; cin>> a >> b >>c ;
		adj[a].push_back({b,c});
	}
	dijkstra(1);
	if(kc[n]==1e18) {
		cout << "-1";
		return 0;
	}
	cout << kc[n];
}

