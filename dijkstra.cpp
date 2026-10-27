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
signed main(){
	
	int n,m;
	cin >> n;
	m=n-1;
	for(int i=1;i<=n;++i) kc[i]=1e18;
	for(int i=1;i<=m;i++){
		int a,b,c; cin>> a >> b >>c ;
		adj[a].push_back({b,c});
	}
	dijkstra(1);
//	cout << kc[n];
	for(int i=1;i<=n;i++) cout << kc[i] << " ";
}
