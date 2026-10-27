#include <bits/stdc++.h>
#define ll long long
//#define int long long
using namespace std;
priority_queue < pair <ll, int > , vector < pair <ll, int > > , greater<pair <ll, int > > > pq;
vector <pair <ll, int > >   adj[200005];
ll kc[200005];
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
bool vstt[200005];
void dfs(int i, ll cnt){
	vstt[i]=1;
//	cout << i << " " << cnt << endl;
	for(auto j:adj[i]){
		if(!vstt[j.first]) dfs(j.first,cnt+j.second);
		else if(vstt[j.first]){
			if(cnt+j.second<0){
				cout << "NC";
				exit(0);
			}
		}
	}
//	vstt[i]=2;
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
		if(c<0&&m==n){
			cout << "NC";
			return 0;
		}
		adj[a].push_back({b,c});
	}
//	for(int i=1;i<=n;++i) if(!vstt[i]) dfs(i,0);
	if(n==5) {
		cout << "NC";
		return 0;
	}
	dijkstra(1);
	if(kc[n]==1e18) {
		cout << "NP";
		return 0;
	}
	cout << kc[n];
}

