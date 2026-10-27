#include <bits/stdc++.h>
using namespace std;
int n,q;
vector <int> adj[500005];
const long long inf=1e16;
using ll=long long;
ll maxx[(1<<22)+3],mask[500005];
ll dep[500005],sz[500005];
int tin[500005],big[500005],eu[500005],timer=0;
ll ans[5000005];
void dfs(int u){
    tin[u]=++timer;
    eu[timer]=u;
    sz[u]=1;
    for(auto i:adj[u]){
        dep[i]=dep[u]+1;
        dfs(i);
        sz[u]+=sz[i];
        if(big[u]==0||sz[i]>sz[big[u]]) big[u]=i;
    }
}
void add(int u){
    for(int i=tin[u];i<tin[u]+sz[u];i++) {
        int x=eu[i];
        maxx[mask[x]]=max(maxx[mask[x]],dep[x]);
    }
}
void del(int u){
    for(int i=tin[u];i<tin[u]+sz[u];i++) maxx[mask[eu[i]]]=-inf;
}
void cal(int u, int root){
     for(int i=tin[u];i<tin[u]+sz[u];i++){
        int x=eu[i];
        int m=mask[x];
        ans[root]=max(ans[root],dep[x]+maxx[m]-2*dep[root]);
        for(int k=0;k<22;++k){
            int w=m^(1<<k);
            ans[root]=max(ans[root],dep[x]+maxx[w]-2*dep[root]);
        }
     }
}
void dfs2(int u, bool keep){
    for(auto i:adj[u]) if(i!=big[u]) dfs2(i,0);
    if(big[u]!=0) dfs2(big[u],1);
    for(auto i:adj[u]) {
        if(i!=big[u]){
            cal(i,u);
            add(i);
        }
    }
    ans[u]=max(ans[u],-dep[u]+maxx[mask[u]]);
    for(int k=0;k<22;++k){
         int w=mask[u]^(1<<k);
        ans[u]=max(ans[u],-dep[u]+maxx[w]);
    }
    maxx[mask[u]]=max(maxx[mask[u]],dep[u]);
    for(auto i:adj[u]) ans[u]=max(ans[u],ans[i]);
    if(!keep) del(u);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i=2;i<=n;i++){
        int u;
        char c ;cin >> u >> c;
        adj[u].push_back(i);
        mask[i]=mask[u]^(1<<(c-'a'));
        // adj[i].push_back(u);
    }
    for(int i=0;i<(1<<22);++i) maxx[i]=-inf;
    dfs(1);
    dfs2(1,1);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    return 0;
}