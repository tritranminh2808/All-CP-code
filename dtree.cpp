#include <bits/stdc++.h>
using namespace std;
bool existA[400005],existB[400005];
vector <int> adj[400004];
int dep1[400005];
void dfs(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        dep1[i]=dep1[u]+1;
        dfs(i,u);
    }
}
int adep[400005],bdep[400005];
void dfa(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        adep[i]=adep[u]+1;
        dfa(i,u);
    }
}
void dfb(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        bdep[i]=bdep[u]+1;
        dfb(i,u);
    }
}
int main(){
    freopen("dtree.inp","r",stdin);
	freopen("dtree.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin >> n >> q;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    vector <pair <int, int > > v;
    multiset<pair <int , int > > vb;
    for(int i=1;i<=n;i++) {
        v.push_back({dep1[i],i});
        existA[i]=1;
    }
    sort(v.begin(),v.end());
    // for(int i=1;i<=n;i++) 
    while(q--){
        int d; cin >> d;
        for(int i=1;i<=n;i++){
            adep[i]=0;
            bdep[i]=0;
        }
        vb.insert({dep1[d],d});
        existA[d]=0;
        existB[d]=1;
        while(!existA[v.back().second]) v.pop_back();
        dfa(v.back().second,0);
        int ans=0;
        for(int i=1;i<=n;i++) if(existA[i]) ans=max(ans,adep[i]);
        cout << ans << " ";
        dfb(vb.rbegin()->second,0);
        ans=0;
        for(int i=1;i<=n;i++) if(existB[i]) ans=max(ans,bdep[i]);
        cout << ans << "\n";
    }
    return 0;
}