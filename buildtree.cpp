#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
using ll=long long;
int par[200005];
int pararr[200005];
ll paredge[200005];
ll distroot[200005];
int S;
vector <pair <int, ll> > adj[200005];
int ans[200005];
ll c[100005],w[100005];
int sz[200005],n,m;
const int mod=1e9+7;
int find(int u) {
    if(par[u]<0) return u;
    return par[u]=find(par[u]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
set <int> jjj,jjjj;
void dfs1(int u,int v){
    sz[u]=1;
    for(auto i:adj[u]){
        if(i.first==v) continue;
        dfs1(i.first,u);
        sz[u]+=sz[i.first];
    }
}
void dfs2(int u, int v,int cmsize){
    for(auto i:adj[u]){
        if(i.first==v) continue;
        ans[i.first]=ans[u]+(cmsize-2*sz[i.first])*i.second;
        dfs2(i.first,u,cmsize);
    }
}
void cok1(){
     for(int v:jjj){ 
        pararr[v]=0; 
        paredge[v]=0; 
        sz[v]=0; 
        distroot[v]=0; 
        ans[v]=0; 
    }
    dfs1(*jjj.begin(),0);
    int cmp=sz[*jjj.begin()];
    int res=0;
    for(auto i:jjj)  {
        if(pararr[i]==0) continue;
        res=(res+paredge[i]*sz[i]*(cmp-sz[i])+mod)%mod;
    }
    cout << res%mod;
}
void cok2(){
    vector <int> com1,com2;
    com1.push_back(*jjj.begin());
    for(auto i:jjj){
        if(i==*jjj.begin())continue;
        if(find(i)!=find(com1.back())) com2.push_back(i);
        else com1.push_back(i);
    }
    dfs1(com1.back(),0);
    dfs2(com1.back(),0,com1.size());
    dfs1(com2.back(),0);
    dfs2(com2.back(),0,com2.size());
    int res=1e18;
    int gg=S*com1.size()%mod;
    for(auto i:com1) res=min(res,ans[i]+gg);
    int sol=1e18;
    for(auto i:com2) sol=min(sol,res*ans[i]%mod);
    cout << sol%mod;

}
signed main(){
    freopen("buildtree.inp","r",stdin);
	freopen("buildtree.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>> n >> m;
    if(m==n-1){
        vector <int> a(m+1);
        for(int i=1;i<=m;i++) cin >> a[i];
        ll sum=0,ans=0;
        for(int i=1;i<=m;i++) {
            ans=(ans+a[i])%mod;
            ans=(ans+sum+a[i]*(i-1))%mod;
            sum+=a[i];
        }
        cout << ans;
        return 0;
    }
    cin >> S;
    for(int i=1;i<=n;i++) par[i]=-1;
    
    for(int i=1;i<n-1;i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        jjj.insert(u);
        jjj.insert(v);
        add(u,v);
    }
    for(auto i:jjj) jjjj.insert(find(i));
   
    if(jjjj.size()==1){
         dfs1(*jjj.begin(),0);
        dfs2(*jjj.begin(),0,jjj.size());
        cok1();
        return 0;
    }
    else {
        cok2();
        return 0;
    }
    return 0;
}