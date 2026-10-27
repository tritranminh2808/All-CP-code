#include <bits/stdc++.h>
using namespace std;
int n,q;
vector < pair <int, int > > adj[200005];
bool block[5005];
int dep[200005],jump[200005][20];
long long high[200005];
vector <int> euler;
long long ans=0;
bool vst[200005];
void dfs(int u,int v){
    euler.push_back(u);
    for(auto i:adj[u]){
        if(i.first==v) continue;
        dep[i.first]=dep[u]+1;
        high[i.first]=high[u]+i.second;
        jump[i.first][0]=u;
        dfs(i.first,u);
    }
}
void dfs2(int u,int v){
    for(auto i:adj[u]){
        if(i.first==v||block[i.first]) continue;
        high[i.first]=high[u]+i.second;
        ans=max(ans,high[i.first]);
        dfs2(i.first,u);
    }
}
vector <int> lay;
void cmm(int u, int v){
    if(adj[u].size()==1)lay.push_back(u);
    for(auto i:adj[u]){
        if(i.first==v) continue;
        if(block[i.first]){
            lay.push_back(u);
            continue;
            // return;
        }
        cmm(i.first,u);
    }
    
}
vector <pair <int, int > > edge;
void sub1(){
    while(q--){
            int ty=0;cin >> ty;
            if(ty==1){
                ans=0;
                int x,k; cin >> x >> k;
                for(int i=1;i<=n;i++) {
                    block[i]=0;
                    high[i]=0;
                }
                for(int i=1;i<=k;i++){
                    int u; cin >> u;
                    block[u]=1;
                }
                dfs2(x,0);
                cout << ans << "\n";
            }
            else {
                int x;long long w; cin >> x >> w;--x;
                int u=edge[x].first,v=edge[x].second;
                for(auto &i:adj[u]) {
                    if(i.first==v){
                         i.second=w;
                         break;
                    }
                }
                for(auto &i:adj[v]) {
                    if(i.first==u){
                         i.second=w;
                         break;
                    }
                }
            }
        }
}
long long w[200005],a[200005];
int pos[200005];
long long st[800005];
void build(int id, int l, int r){
    if(l==r) {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
void update(int id, int l, int r, int u, int v){
    if(u<l||u>r) return ;
    if(l==r){
        st[id]=v;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    st[id]=st[id*2]+st[id*2+1];
}
long long find(int id, int l, int r,int lf, int rt){
    if(lf>rt) return 0;
    if(lf>r||rt<l) return 0;
    if(lf<=l&&rt>=r) return st[id];
    int mid=(l+r)/2;
    return find(id*2,l,mid,lf,rt)+find(id*2+1,mid+1,r,lf,rt);
}
void subdt(){
    map <pair <int, int > , long long > mp;
    for(int i=0;i<n-1;i++){
        mp[{edge[i].first,edge[i].second}]=w[i+1];
        mp[{edge[i].second,edge[i].first}]=w[i+1];
    }
    for(int i=1;i<=n;i++){
        pos[euler[i]]=i;
        a[i]=mp[{euler[i-1],euler[i]}];
    }
    // for(int i=1;i<=n;i++) cout << a[i] << " ";
    build(1,1,n);
    while(q--){
        int yy=0; cin >> yy;
        if(yy==2){
            int x; long long w;
            cin >> x >> w;
            int u=edge[x-1].first,v=edge[x-1].second;
            if(pos[u]>pos[v]) swap(u,v);
            update(1,1,n,pos[v],w);
        }
        else {
            int k,x; cin >> x >> k;
            vector <int> no(k);
            int lf=0,rt=n+1;
            for(int i=0;i<k;i++) {
                int u; cin >> u;
                if(pos[u]<pos[x]) lf=max(lf,pos[u]);
                else rt=min(rt,pos[u]);
            }
            cout << max(find(1,1,n,lf+2,pos[x]),find(1,1,n,pos[x]+1,rt-1)) << "\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i=1;i<n;i++){
        int u,v,ww;
        cin >> u >> v >> ww;
        adj[u].push_back({v,ww});
        adj[v].push_back({u,ww});
        edge.push_back({u,v});
        w[i]=ww;
    }
    euler.push_back(n+1);
    int start=1;
    for(int i=1;i<=n;++i) if(adj[i].size()==1) start=i;
    dfs(start,0);
    cin >> q;
    if(n<=5000&&q<=5000){
        sub1();return 0;
    }
    bool dt=0;
    for(int i=1;i<=n;i++){  
        if(adj[i].size()>2){
            dt=1;
            break;
        }
    }
    if(!dt){
        // cout << 0;
        // return 0;
        subdt();
    }
    return 0;
}