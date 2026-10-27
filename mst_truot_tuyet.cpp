#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,T;
int a[505][505];
bool b[505][505];
int sz[1000005],par[1000005];
struct pl{
    int u,v,w;
};
vector <pl> canh;
int encode(int x,int y){
    return x*500+y;
}
pair <int, int> decode(int x){
    return {x/500,x%500};
}
bool cmp(pl a, pl b){
    return a.w<b.w;
}
int cnt[1000005];
vector <int> adj[1000005];
int find(int u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(sz[u]>sz[v]){
        par[v]=u;
        sz[u]+=sz[v];
    }
    else{
        par[u]=v;
        sz[v]+=sz[u];
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> T;
    if(T==1){
        cout << 0;
        return 0;
    }
    for(int i=1;i<=n;i++)    for(int j=1;j<=m;j++) cin >> a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> b[i][j];
    vector <int> start;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=encode(i,j);
            par[x]=x;
            sz[x]=1;
            if(i+1<=n){
                int y=encode(i+1,j);
                canh.push_back({x,y,abs(a[i][j]-a[i+1][j])});
            }
            if(j+1<=m){
                int y=encode(i,j+1);
                canh.push_back({x,y,abs(a[i][j]-a[i][j+1])});
            }
            if(b[i][j]) start.push_back(x);
        }
    }
    sort(canh.begin(),canh.end(),cmp);
    for(auto i:start) adj[i].push_back(i);
    for(auto i:canh){
        int u=i.u,v=i.v;
        u=find(u);
        v=find(v);
        if(u==v) continue;
        add(u,v);
        if(par[u]==v) swap(u,v);
        for(auto j:adj[v]) adj[u].push_back(j);
        adj[v].clear();
        if(sz[u]>=T){
            for(auto j:adj[u]) cnt[j]=i.w;
            adj[u].clear();
        }
    }
    int sol=0;
    for(auto i:start) sol+=cnt[i];
    cout << sol;
    return 0;
}