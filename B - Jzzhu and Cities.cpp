#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue < pair < int, int > , vector < pair < int, int > > , greater<pair < int, int > > > pq;
vector <pair < int, int > >   adj[100005];
int kc[100005];
vector < int > t(100005,-1);
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
				t[i.first]=p.second;
			}
		}
	}
}
bool check[100005],chkk[100005];
int sol=0;
vector<int> trace_path(int S, int u) {
    if (u != S && t[u] == -1) return vector<int>(1, -1); 

    vector<int> path;
    while (u != -1) { 
   // cout << u << endl;
        path.push_back(u);
        u = t[u];
    }
    reverse(path.begin(), path.end()); 

    return path;
}
signed main(){
	
	int n,m,k;
	cin >> n >> m>>k;
	for(int i=1;i<=n;++i) kc[i]=1e16;
	for(int i=1;i<=m;i++){
		int a,b,c; cin >>a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dijkstra(1);
	vector <int> goc(n+1);
	for(int i=1;i<=n;i++) goc[i]=kc[i];
//	cout << 1 << " ";
	vector < int> route;
	while(k--){
		int s,y; cin >> s >> y;
		if(check[s]==0){
			check[s]=1;
			route.push_back(s);
		}
		else sol++;
	}
	for(int i=2;i<=n;i++){
		for(auto j: trace_path(1,i)) chkk[j]=1;
	}
	for(auto i : route ) {
		if(chkk[i]==0) sol++;
	}
	cout << sol;
}
