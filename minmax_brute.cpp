#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[100005],n;
vector <int> adj[100005];
int sol=0;
void dfs(int u, int v,vector <int> sech){
    if(adj[u].size()==1&&adj[u][0]==v){
        // cout << u << "\n";
        // for(auto i:sech) cout << i << " ";
        // cout << endl;
        for(int i=0;i<sech.size();++i){
            for(int j=0;j<i;j++) {
                sol+=min(max(a[sech[i]],a[sech[j]]),max(b[sech[i]],b[sech[j]]));
                // cout << i << " " << j <<" "<< min(max(a[i],a[j]),max(b[i],b[j])) <<"\n";
            }
        }
    }
    for(auto i: adj[u]){
        if(i==v) continue;
        vector <int> ngu=sech;
        ngu.push_back(i);
        dfs(i,u,ngu);
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int j=1;j<=n;j++) cin >> b[j];
    for(int i=1;i<n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,{1});
    cout << sol;
    return 0;
}