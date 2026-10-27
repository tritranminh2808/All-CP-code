#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
struct pl{
	int d,id,c;
};
struct cute{
	int val,cnt;
};
bool qua (cute a, cute b){
	return a.val<b.val;
}
struct cmp{
	bool operator ()(const pl &a,const pl &b){
		return a.d>b.d;
	}
};
const int mod=1e9+7;
//priority_queue<pl,vector <pl> , cmp> pq2;
vector <pair < int, int > >   adj[200005];
int kc[200005],cnt[200005],smax[200005],smin[200005];
int minn,n,m,k;
vector <cute> sol;
void dijkstra2(int u)
{
	kc[u]=0;
	pq.push({kc[u],u});
	while(!pq.empty()){
		pair <int, int > p=pq.top();
		pq.pop();
		if(kc[p.second]<p.first) continue;
		for(auto i: adj[p.second]){
			if(p.first+i.second<kc[i.first]){
				cnt[i.first]=cnt[p.second];
				kc[i.first]=p.first+i.second;
				pq.push({kc[i.first],i.first});
			}
			else if(p.first+i.second==kc[i.first]) cnt[i.first]=(cnt[i.first]+cnt[p.second])%123456789;

		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i) kc[i]=1e18;
	while(m--){
		int a,b,c; cin>> a >> b >>c ;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	cnt[1]=1;
	dijkstra2(1);
	cout << kc[n] << "\n" << cnt[n];
	return 0;
	
}
