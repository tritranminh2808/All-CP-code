#include <bits/stdc++.h>
using namespace std;
int n,b;
int c[100005],d[100005],sz[100005];
vector <int> adj[100005];
void sizee(int u, int v){
    for(auto i:adj[u]){
        if(i==v) continue;
        sizee(i,u);
        sz[u]+=sz[i];
    }
}
int dp0[5005][5005],dp1[5005][5005];
void dfs(int u){
    dp0[u][0]=dp1[u][0]=0;
    dp0[u][1]=c[u];
    dp1[u][1]=c[u]-d[u];
    int chose=1;
    for(auto i:adj[u]){
        dfs(i);
        
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> b;
    for(int i=1;i<=5000;i++) for(int j=1;j<=5000;j++) { dp1[i][j]=INT_MAX; dp0[i][j]=INT_MAX;}
    memset(sz,1,sizeof(sz));
    for(int i=1;i<=n;i++){
        if(i==1) cin >> c[i] >> d[i];
        else{
            cin >> c[i] >> d[i];
            int u; cin >> u;
            adj[i].push_back(u);
            adj[u].push_back(i);
        }
    }
    sizee(1,0);
    dfs(1);
    return 0;
}