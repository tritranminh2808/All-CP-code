#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n,m,T;
int sz1[1000005],par1[1000005],sz2[1000005],par2[1000005];
struct pl{
    int u,v,w,id;
};
vector <pl> canh;
bool cmp(pl a, pl b){
    return a.w>b.w;
}
void reset(){
    for(int i=1;i<=n;i++){
        par1[i]=i;
        sz1[i]=1;
        par2[i]=i;
        sz2[i]=1;
    }
}
int find1(int u){
    if(u==par1[u]) return u;
    return par1[u]=find1(par1[u]);
}
void add1(int u, int v){
    u=find1(u);
    v=find1(v);
    if(sz1[u]>sz1[v]) swap(u,v);
    sz1[v]+=sz1[u];
    par1[u]=v;
}
int find2(int u){
    if(u==par2[u]) return u;
    return par2[u]=find2(par2[u]);
}
void add2(int u, int v){
    u=find2(u);
    v=find2(v);
    if(sz2[u]>sz2[v]) swap(u,v);
    sz2[v]+=sz2[u];
    par2[u]=v;
}
bool lay[1000005];
vector <pl> loai1,loai2,loai3;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    reset();
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        if(w==1) loai1.push_back({u,v,w,i+1});
        if( w==2) loai2.push_back({u,v,w,i+1});
        if(w==3) loai3.push_back({u,v,w,i+1});
    }
    for(auto i:loai3){
        int x1=i.u,y1=i.v,x2=i.u,y2=i.v;
        x1=find1(x1);
        y1=find1(y1);
        x2=find2(x2);
        y2=find2(y2);
        if(x1==y1&&x2==y2) continue;
        add1(x1,y1);
        add2(x2,y2);
        lay[i.id]=1;
    }
    for(auto i:loai1){
        int x=i.u,y=i.v;
        x=find1(x);
        y=find1(y);
        if(x==y) continue;
        add1(x,y);
        lay[i.id]=1;
        
    }
    for(auto i:loai2){
        int x=i.u,y=i.v;
        x=find2(x);
        y=find2(y);
        if(x==y) continue;
        add2(x,y);
        lay[i.id]=1;
        
    }
    int p1=find1(1),p2=find2(1);
    for(int i=1;i<=n;i++) {
        if(find1(i)!=p1||find2(i)!=p2){
            cout << -1;
            return 0;
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++) if(!lay[i]) cnt++;
    cout << cnt << "\n";
    for(int i=1;i<=m;i++) if(!lay[i]) cout << i << "\n";
    return 0;
}