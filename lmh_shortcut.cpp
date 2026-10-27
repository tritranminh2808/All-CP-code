#include <bits/stdc++.h>
#define int long long
using namespace std;
struct pl{
	int val, id;
	vector <int> s;
};
struct cmp{
	bool operator ()(pl &a, pl &b){
		return a.val>b.val;
	}
};
priority_queue < pl , vector <pl> ,cmp > pq;
vector <pair < int, int > >   adj[100005];
int kc[100005],c[100005];
vector <int> truy[100005];
bool chk=0;
vector <int> so(vector <int> &a, vector <int> &b){
	for(int i=0;i<min(a.size(),b.size());++i){
		if(a[i]<b[i]) {
			chk=1;
			return a;
		}
		else if(a[i]>b[i]) return b;
	}
	return a;
}
void dijkstra(int u)
{
	kc[u]=0;
	vector <int> stt;
	stt.push_back(u);
	truy[u]=stt;
	pq.push({kc[u],u,stt});
	while(!pq.empty()){
		pl p=pq.top();
		pq.pop();
		if(kc[p.id]<p.val) continue;
		for(auto i: adj[p.id]){
			if(p.val+i.second==kc[i.first]){
				vector <int> str2=p.s;
				str2.push_back(i.first);
				chk=0;
				truy[i.first]=so(str2,truy[i.first]);
				if(chk) pq.push({kc[i.first],i.first,truy[i.first]});
				continue;
			}
			if(p.val+i.second<kc[i.first]){
				kc[i.first]=p.val+i.second;
				vector <int> str2=p.s;
				str2.push_back(i.first);
				truy[i.first]=str2;
				pq.push({kc[i.first],i.first,str2});
			}
		}
	}
}
int cnt[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,T;
	cin >> n >> m >> T;
	for(int i=1;i<=n;i++) {
		cin >> c[i];
		kc[i]=1e18;
	}
	while(m--){
		int a,b,c; cin >>a >> b >>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dijkstra(1);
	for(int i=1;i<=n;i++){
		if(c[i]==0) continue;
		for(auto j:truy[i]) cnt[j]+=max(kc[j]-T,(int)0)*c[i];
	}
	int maxx=-1e18;
	for(int i=1;i<=n;i++) maxx=max(maxx,cnt[i]);
	cout << maxx;
}
