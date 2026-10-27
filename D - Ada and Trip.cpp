#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
vector <pair < int, int > >   adj[1000005];
int kc[500005];
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
	ios_base ::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin >> n >> m>>q;
	
	for(int i=1;i<=m;i++){
		int a,b,c; cin >>a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	while(q--){
		int ppp; cin >> ppp;
		//memset(kc,1e16,100005);
		for(int i=0;i<n;++i) kc[i]=1e16;
		dijkstra(ppp);
		int sol=-1e18,dem=0;
		for(int i=0;i<n;i++){
			if(kc[i]==1e16) continue;
			sol=max(sol,kc[i]);
		}
		for(int i=0;i<n;i++) if(kc[i]==sol) dem++;
		//if( sol==0) cout << "0 1\n" ;
		cout << sol << " " << dem << "\n";
	}
	
	//for(int i=1;i<=n;i++) cout << kc[i] << " ";
}
