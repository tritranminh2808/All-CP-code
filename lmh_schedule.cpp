#include <bits/stdc++.h>
using namespace std;
int n, m;
using ll=long long;
vector<vector<int>> adj;
vector<bool> vis;  
vector<int> order;
int val[200005];
vector <pair <int, int> > ada[200005];
bool lap;
void dfs(int u) {
    vis[u]=1;
    for (int v:adj[u]) {
        if (!vis[v])  dfs(v);
    }
    order.push_back(u);
}
ll kc[200005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
    	cin >> val[i];
    	kc[i]=val[i];
	}
    adj.assign(n+1, {});
    vis.assign(n+1, 0);
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ada[a].push_back({b,val[b]});
    }
    for(int u = 1; u <= n; u++){
        if(vis[u]==0) dfs(u);
    }
    reverse(order.begin(), order.end());
    ll s=0;
    for(auto i:order){
    	for(auto u:ada[i]) kc[u.first]=max(kc[u.first],kc[i]+u.second);
	}
	for(int i=1;i<=n;i++) s=max(s,kc[i]);
	cout << s << "\n";
	for(int i=1;i<=n;i++) cout << kc[i]-val[i]+1 << "\n";
    return 0;
}

