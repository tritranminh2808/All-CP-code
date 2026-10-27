#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
vector <pair < int, int > >   adj[400005];
int kc[400005];
vector <int > kkkk;
int n,m,k;
void dijkstra(int u)
{
	kc[u]=0;
	pq.push({kc[u],u});
	while(!pq.empty()){
		pair <int, int > p=pq.top();
		pq.pop();
		if(kc[p.second]<p.first) continue;
		for(auto i: adj[p.second]){
			if(i.first==n) kkkk.push_back(p.first+i.second);
			if(p.first+i.second<=kc[i.first]){
				
				kc[i.first]=p.first+i.second;
				pq.push({kc[i.first],i.first});
			}
		}
	}
}
signed main(){
	
	
	cin >> n >> m>>k;
	for(int i=1;i<=n;++i) kc[i]=1e16;
	for(int i=1;i<=m;i++){
		int a,b,c; cin >>a >> b >> c;
		adj[a].push_back({b,c});
	}
	dijkstra(1);
	sort(kkkk.begin(),kkkk.end());
	for(int i=0;i<k;i++) cout << kkkk[i] << " ";
}
