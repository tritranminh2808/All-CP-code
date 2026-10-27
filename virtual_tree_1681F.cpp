#include<bits/stdc++.h>
using namespace std; 
struct pl{
    int u,v,w;
};
vector <pair <int, int > > adj[500005];
vector <int> adj_ao[500005];
int n;
int dep[500005],jump[20][500005],num[500005],sz[500005],rem[500005],timer=0,par[500005];
long long dp[2][500005];
int color[500005];
vector <int> tour;
void dfs(int u, int v){
    num[u]=++timer;
    par[u]=v;
    sz[u]=1;
    tour.push_back(u);
    for(auto i:adj[u]){
        if(i.first==v) continue;
        dep[i.first]=dep[u]+1;
        jump[0][i.first]=u;
        color[i.first]=i.second;
        dfs(i.first,u);
        sz[u]+=sz[i.first];
    }
}
void build(){
    for(int i=1;i<=19;i++){
        for(int j=1;j<=n;j++) jump[i][j]=jump[i-1][jump[i-1][j]];
    }
}
int lca(int u, int v){
    if(dep[u]>dep[v]) swap(u,v);
    int dist=dep[v]-dep[u];
    for(int i=19;i>=0;i--){
        if(dist>=(1<<i)){
            v=jump[i][v];
            dist-=(1<<i);
        }
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(jump[i][u]==0||jump[i][v]==0||jump[i][u]==jump[i][v]) continue;
        u=jump[i][u];
        v=jump[i][v];
    }
    return jump[0][u];
}
int base=0;
bool cmp(int a,int b){
    return num[a]<num[b];
}
bool check(int u, int v){
    return lca(u,v)!=u;
}
long long dfs_ao(int u){
    long long res=0;
    // cout << u << " " ;
    for(auto i:adj_ao[u]) res+=dfs_ao(i);
    dp[0][u]=sz[u];
    for(auto i:adj_ao[u]) dp[0][u]-=sz[i];
    // cout << u << " " << dp[0][u] << "\n";
    dp[1][u]=0; 
    
    for(auto i:adj_ao[u]){
        if(color[i]!=base){
            // cout<< u << " " << i << "\n";
            // return 0;
            res += dp[0][i] * 1ll * dp[1][u];
			res += dp[1][i] * 1ll * dp[0][u];
			dp[0][u] += dp[0][i];
			dp[1][u] += dp[1][i];
            
        }
        else{
            res += dp[0][i] * 1ll * dp[0][u];
			dp[1][u] += dp[0][i];
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    unordered_map<int, vector <int> >mp;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,0);
    for(auto i:tour) for(auto j:adj[i]) mp[j.second].push_back(j.first);
    build();
    // for(int i=1;i<=n;i++) cout << sz[i] << " ";
    long long ans=0;
    for(auto pp:mp){
       auto v=pp.second;
       v.push_back(1);
       base=pp.first;
       sort(v.begin(),v.end(),cmp);
        int m=v.size();
        for(int i=1;i<m;i++) v.push_back(lca(v[i],v[i-1]));
        sort(v.begin(),v.end(),cmp);
        v.erase(unique(v.begin(),v.end()),v.end());
        stack<int> st;
        for(auto i:v){
            while(!st.empty()&&check(st.top(),i)) st.pop();
            if(!st.empty()) adj_ao[st.top()].push_back(i);
            st.push(i);
        }
        // cout << base << "\n";
        // for(int i=1;i<=n;i++) for(auto j:adj_ao[i]) cout << i << " " << j << "\n";
        
        ans+=dfs_ao(v[0]);
        // cout << ans << "\n";
        for(auto i:v) adj_ao[i].clear();
    }
    cout << ans;
    return 0;
}