#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n,m;
set <int> adj[100005];
int num[100005],low[100005],bel[100005],sz[100005],dem[100005];
int cnt=0,cc=0;
bool del[100005];
stack <int> st;
int comp[100005],cntcomp=0;
void dfs(int u){
    num[u]=low[u]=++cnt;
    st.push(u);
    for(auto i:adj[u]){
        if(!del[i]){
            if(num[i])low[u]=min(low[u],num[i]);
            else {
                dfs(i);
                low[u]=min(low[i],low[u]);
            }
        }
    }
    if(low[u]==num[u]){
        int v;
        ++cntcomp;
        do{
            v=st.top();
            st.pop();
            del[v]=1;
            comp[v]=cntcomp;
        }while(v!=u);
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; 
        cin >> u >> v;
        adj[u].insert(v);
    }
    for(int i=1;i<=n;i++) if(!num[i]) dfs(i);
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[comp[i]]=i;
    if(mp.size()==1) cout << "YES";
    else {
        cout << "NO\n";
        int x=-1,y=-1;
        for(auto i:mp){
            if(x==-1) x=i.second;
            else{
                y=i.second;
                break;
            }
        }
        cout << x << " " << y;
    }
}