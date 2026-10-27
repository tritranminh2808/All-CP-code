#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n,m;
set <pair <int, int > > adj[100005];
int num[100005],low[100005],bel[100005],sz[100005],dem[100005];
int cnt=0,cc=0;
bool del[100005];
stack <int> st;
int comp[100005],cntcomp=0;
int cau=0,khop=0;
void dfs(int u,int p){
    bool phaikhopkhong=0;
    int cntchild=0;
    num[u]=low[u]=++cnt;
    for(auto i:adj[u]){
       
        if(i.second!=p){
            if(num[i.first])  low[u]=min(low[u],num[i.first]);
            else {
                dfs(i.first,i.second);
                cntchild++;
                low[u]=min(low[u],low[i.first]);
                if(low[i.first]>num[u]) cau++;
                if(low[i.first]>=num[u]) phaikhopkhong=1;
            }
        }
    }
    if((phaikhopkhong&&p!=0)||(p==0&&cntchild>1)) khop++;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v; 
        cin >> u >> v;
        adj[u].insert({v,i});
        adj[v].insert({u,i});
    }
    for(int i=1;i<=n;i++) if(!num[i]) dfs(i,0);
    cout << khop << "\n" << cau;
}