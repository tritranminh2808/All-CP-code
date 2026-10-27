#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
struct pl{
	ll dis; int x;
	bool c;
};
struct cmp{
	bool operator ()(pl &a, pl &b){
		return a.dis>b.dis;
	}
};
priority_queue < pl, vector < pl > , cmp > pq;
vector <pair <ll, int > >   adj[200005],chi[200005];
ll kc[200005][2];
void dijkstra(int u)
{
	kc[u][0]=0;
	pq.push({0,u,0});
	while(!pq.empty()){
		pl p=pq.top();
		pq.pop();
		if(kc[p.x][p.c]<p.dis) continue;
		for(auto i: adj[p.x]){
			if(p.dis+i.second<kc[i.first][p.c]){
				kc[i.first][p.c]=p.dis+i.second;
				pq.push({kc[i.first][p.c],i.first,p.c});
			}
		}
		if(!p.c){
			for(auto i:chi[p.x]){
				if(p.dis+i.second<kc[i.first][1]){
					kc[i.first][1]=p.dis+i.second;
					pq.push({kc[i.first][1],i.first,1});
				}
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,st,ed;
	cin >> n >> m >> k >> st >> ed;
//	m=n-1;
	for(int i=1;i<=n;++i) kc[i][0]=1e16,kc[i][1]=1e16;
	for(int i=1;i<=m;i++){
		int a,b,c; cin>> a >> b >>c ;
		adj[a].push_back({b,c});
	}
	while(k--){
		int a,b,c;
		cin >> a >> b >> c;
		chi[a].push_back({b,c});
		chi[b].push_back({a,c});
	}
	dijkstra(st);
	if(kc[ed][0]==1e16&&kc[ed][1]==1e16) {
		cout << "-1";
		return 0;
	}
	cout << min(kc[ed][0],kc[ed][1]);
}

