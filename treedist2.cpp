#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q,m;
int stt[200005],ed[200005];
int cnt=0;
vector <int> adj[200005];
int dep[200005];
void build_euler(int u, int v){
    stt[u]=++cnt;
    for(auto i:adj[u]){
        if(i==v) continue;
        build_euler(i,u);
    }
    ed[u]=cnt;
}
void dfs(int u, int v){
    for(auto i: adj[u]){
        if(i==v) continue;
        dep[i]=dep[u]+1;
        dfs(i,u);
    }
}
int sol[200005];
void cok(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        sol[i]=sol[u];
        sol[i]-=ed[i]-stt[i]+1;
        sol[i]+=(n-ed[i]+stt[i]-1);
        // cout << i << " "<< sol[i] << "\n";
        cok(i,u);
    }
}
int ans=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n ;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build_euler(1,0);
    dfs(1,0);
    for(int i=1;i<=n;i++) ans+=dep[i];
    sol[1]=ans;
    cok(1,0);
    for(int i=1;i<=n;i++) cout << sol[i] << " ";
	return 0;
}
