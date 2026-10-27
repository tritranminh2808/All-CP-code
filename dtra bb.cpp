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
int road[505][505],floyd[505][505];
vector <int> qu[505];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) floyd[i][j]=1e18;
	}
	for(int i=1;i<=n;++i) floyd[i][i]=0;
	for(int i=1;i<=m;i++){
		int a,b,c; cin>> a >> b >>c ;
		floyd[a][b]=min(floyd[a][b],c);
		floyd[b][a]=min(floyd[b][a],c);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;j++){
				if(floyd[i][j]>floyd[i][k]+floyd[k][j]&&floyd[i][k]!=1e18&&floyd[k][j]!=1e18) floyd[i][j]=floyd[i][k]+floyd[k][j];		
			}
		}
	}
	while(q--){
		int u,v; cin >> u >> v;
		if(floyd[u][v]==1e18) cout << "-1\n";
		else cout << floyd[u][v] << "\n";
	}
}
