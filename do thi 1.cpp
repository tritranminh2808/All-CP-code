#include <bits/stdc++.h>
//#define int long long
using namespace std;
vector <int > adj[200005];
int n,m;
bool vst[200005];
int cnt[200005],par[200005];
void bfs(int u){
	queue<int> q;
	vst[u]=1;
	cnt[u]=0;
	par[u]=0;
	q.push(u);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(auto i:adj[p]){
			if(!vst[i]){
				vst[i]=1;
				par[i]=p;
				cnt[i]=cnt[p]+1;
				q.push(i);
				continue;
			}
			if(i!=par[p]){
				vector <int> k1,k2;
				int x=p;
				while(x!=0){
					k1.push_back(x);
					x=par[x];
				}
				x=i;
				while(x!=0){
					k2.push_back(x);
					x=par[x];
				}
				int sz1=k1.size()-1,sz2=k2.size()-1;
				while(sz1>=0&&sz2>=0&&k1[sz1]==k2[sz2]){
					sz1--;
					sz2--;
					
				}
				sz1++;
				sz2++;
				vector <int> trace;
				for(int j=0;j<=sz1;++j) trace.push_back(k1[j]);
				for(int j=sz2-1;j>=0;--j) trace.push_back(k2[j]);
				trace.push_back(p);
				cout << trace.size() << "\n";
				for(auto y:trace) cout << y << " ";
				exit(0);
			}
		}
	}
//	cout << -1;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(m--){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
//		adj[v].push_back(u);
	}
//	bfs(1);
	for(int i=1;i<=n;i++) {
		if(!vst[i]) bfs(i);
	}
	cout  << "IMPOSSIBLE";
}
