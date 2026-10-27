#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;
//priority_queue<pl,vector <pl> , cmp> pq2;
vector <pair < int, int > >   adj[200005];
int kc[200005],cnts[200005],cntt[200005],kcs[200005],kct[200005];
int s,t,n,m;
const int inf=1e18;
// const int mod=1e9+7;
struct pl{
    int u,v,w;
};
void dijkstras(int u)
{
    priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
	kc[u]=0;
	pq.push({kc[u],u});
	while(!pq.empty()){
		pair <int, int > p=pq.top();
		pq.pop();
		if(kc[p.second]<p.first) continue;
		for(auto i: adj[p.second]){
			if(p.first+i.second<kc[i.first]){
				cnts[i.first]=cnts[p.second]%mod;
				kc[i.first]=p.first+i.second;
				pq.push({kc[i.first],i.first});
			}
			else if(p.first+i.second==kc[i.first]){
                cnts[i.first]=(cnts[i.first]+cnts[p.second])%mod;
            }
		}
	}
}
vector <pl> edge;
void dijkstrat(int u)
{
    priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
	kc[u]=0;
	pq.push({kc[u],u});
	while(!pq.empty()){
		pair <int, int > p=pq.top();
		pq.pop();
		if(kc[p.second]<p.first) continue;
		for(auto i: adj[p.second]){
			if(p.first+i.second<kc[i.first]){
				cntt[i.first]=cntt[p.second]%mod;
				kc[i.first]=p.first+i.second;
				pq.push({kc[i.first],i.first});
			}
			else if(p.first+i.second==kc[i.first]){
                cntt[i.first]=(cntt[i.first]+cntt[p.second])%mod;
            }
		}
	}
}
using i128=__int128_t;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	for(int i=1;i<=n;++i) kc[i]=inf;
	while(m--){
		int a,b,c; cin>> a >> b >>c ;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
        edge.push_back({a,b,c});
	}
	cnts[s]=1;
    cntt[t]=1;
	dijkstras(s);

    for(int i=1;i<=n;i++) {
        kcs[i]=kc[i];
        kc[i]=inf;
    }
    dijkstrat(t);
    for(int i=1;i<=n;i++) kct[i]=kc[i];
    // cout << cnts[t] << " " << cntt[s];
    int thua=0;
    int minn=kcs[t];
    for(int i=1;i<=n;i++){
        if(kcs[i]+kct[i]==minn&&kct[i]==kcs[i]) thua=(thua+(i128)(cnts[i]*cntt[i])%mod*(i128)(cnts[i]*cntt[i])%mod)%mod;// diem o giua
    }
    for(auto i:edge){//canh o giua
        int u=i.u,v=i.v;
        if(kcs[u]+i.w+kct[v]==minn&&kcs[u]*2<minn&&2*kct[v]<minn) thua=(thua+(i128)(cnts[u]*cntt[v])%mod*(i128)(cnts[u]*cntt[v])%mod)%mod;
        swap(u,v);
        if(kcs[u]+i.w+kct[v]==minn&&2*kcs[u]<minn&&2*kct[v]<minn) thua=(thua+(i128)(cnts[u]*cntt[v])%mod*(i128)(cnts[u]*cntt[v])%mod)%mod;
    }
    cout <<( (cntt[s]*cnts[t]%mod-thua)%mod+mod)%mod;
	return 0;
	
}
