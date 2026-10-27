#include <bits/stdc++.h>
#define int long long
using namespace std;
struct PL{
	int h,w,t;
};
struct me_may_beo{
	int dis,x,cnt;
};
struct cmp{
	bool operator()( me_may_beo &u, me_may_beo &v){
		return u.dis>v.dis;
	}
};
priority_queue < me_may_beo, vector < me_may_beo > , cmp > pq;
vector <PL> adj[2000005];
int kc[2000005];
void dijkstra(int u)
{
	kc[u]=0;
	pq.push({kc[u],u,0});
	while(!pq.empty()){
		me_may_beo p=pq.top();
		pq.pop();
		if(kc[p.x]<p.dis) continue;
		for(auto i: adj[p.x]){
			if(p.dis+i.w+i.t*p.cnt<kc[i.h]){
				kc[i.h]=p.dis+i.w+i.t*p.cnt;
				pq.push({kc[i.h],i.h,p.cnt+1});
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i) kc[i]=1e18;
	while(m--){
		int a,b,c,d; cin>> a >> b >>c >> d ;
		adj[a].push_back({b,c,d});
		adj[b].push_back({a,c,d});
	}
	dijkstra(1);
	if(kc[n]==1e18) cout << -1;
	else cout << kc[n];
	return 0;
}
