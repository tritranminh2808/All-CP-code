#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
int n,m,s,k;
ll c[200005];
vector <pair <int, ll> > adj[200005];
unordered_map<int, ll>  mp[2005];
ll ans=-1;
// int s=0;
void dfs(int u, int v, ll val){
    if(v==s){
        if(u==1) ans=max(ans,val);
        return;
    }
    for(auto i:adj[u]){
        int x=v+i.second;
        if(x>s) continue;
        ll them=c[i.first];
        if(mp[i.first].count(x)) them+=mp[i.first][x];
        dfs(i.first,x,val+them);
    }
}
signed main(){
    freopen("festival.inp","r",stdin);
	freopen("festival.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m >> s >> k;
	for(int i=1;i<=n;i++) cin >> c[i];
	for(int i=1;i<=m;i++){
		int u,v,w; cin >> u >> v >> w;
		adj[u].push_back({v,w});
	}
    for(int i=0;i<k;i++){
        int t,x,y; 
        cin >> t >> x >> y;
        mp[x][t]+=y;
    }
    int stt=c[1];
    if(mp[1].count(0)) stt+=mp[1][0];
    dfs(1,0,stt);
    cout << ans;
    return 0;
}