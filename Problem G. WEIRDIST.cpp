#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=4e18;
int n;
vector<pair<int,int>> adj[1000005], sech[1000005];
int d1[1000005], dp[1000005];
int up[1000005][18], dep[1000005];

void dfs0(int u,int p){
    for(auto e:adj[u]){
        int v=e.first; int w=e.second;
        if(v==p) continue;
        d1[v]=d1[u]+w;
        up[v][0]=u;
        dep[v]=dep[u]+1;
        for(int j=1;j<18;++j)
            up[v][j]=up[ up[v][j-1] ][j-1];
        dfs0(v,u);
    }
}

int lca(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    int dif=dep[b]-dep[a];
    for(int j=0;j<18;++j)
        if(dif>>j&1) b=up[b][j];
    if(a==b) return a;
    for(int j=17;j>=0;--j)
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    return up[a][0];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1,u,v;i<n;i++){
        int w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    d1[1]=0;
    dfs0(1,0);
    for(int u=1;u<=n;++u)
      for(int v=u+1;v<=n;++v){
        int d = d1[u]+d1[v] - 2*d1[lca(u,v)];
        sech[u].push_back({v,d});
      }
    for(int i=1;i<=n;++i) dp[i]=INF;
    dp[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair <int,int> >> pq;
    pq.push({0,1});
    while(!pq.empty()){
        pair <int, int > pp=pq.top(); pq.pop();
    	int du=pp.first, u=pp.second;
        if(du>dp[u]) continue;
        for(auto e:sech[u]){
            int v=e.first; int w=e.second;
            if(dp[v]>du+w){
                dp[v]=du+w;
                pq.push({dp[v],v});
            }
        }
    }
    for(int i=1;i<=n;++i) cout<<dp[i]<< " ";
    return 0;
}

