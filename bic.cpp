#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> adj[100005];
const long long mod=1e9;
int n,m;
int vst[100005];
bool lap=0;
vector <int> topo;
int sz[100005],par[100005];
void dfs(int u){
    vst[u]=1;
    for(auto i:adj[u]){
        if(!vst[i]){
            dfs(i);
            if(lap) return;
        }
        else if(vst[i]==1) {
            lap=1;
            return;
        }
    }
    vst[u]=2;
    topo.push_back(u);
}
int find(int u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void add(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
}
long long dp[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
    // cout << "ngu";
    vector <pair <int, int > > edge;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        edge.push_back({u,v});
        add(u,v);
    }
    int goc=find(1);
    if(find(2)!=goc){
        cout << 0;
        return 0;
    }
	for(int i=0;i<m;i++) adj[edge[i].first].push_back(edge[i].second);
    
	for(int i=1;i<=n;i++){
        if(!vst[i]&&find(i)==goc){
            dfs(i);
            if(lap){
                cout << "inf";
                return 0;
            }
        }
    }
    dp[1]=1;
    reverse(topo.begin(),topo.end());
    int ch=0;
    for(auto i:topo){
        // cout << i << " ";
        for(auto j:adj[i]) {
            dp[j]=(dp[j]+dp[i]);
            if(j==2&&dp[j]>=1e9){
                ch=1;
                dp[j]%=mod;
            }
        }
        
    }
    vector <int> v;
    if(!ch){
        cout << dp[2];
        return 0;
    }
    long long x=dp[2];
    
    while(x!=0){
        v.push_back(x%10);
        x/=10;
    }
    for(int i=0;i<10;i++) v.push_back(0);
    while(v.size()>9) v.pop_back();
    for(int i=8;i>=0;i--) cout << v[i];
	return 0;
	
}
