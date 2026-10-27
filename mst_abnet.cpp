#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
int par[10005],sz[10005];
struct pl{
    int u,v,w,id;
};
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
bool lay[100005];
bool cmp(pl a, pl b){
    return a.w>b.w;
}
bool cmp2(pl a, pl b){
    return a.w<b.w;
}
void reset(int n){
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int ii=1;
        int n,m; cin >> n >> m;
        reset(n);
        for(int i=1;i<=m;i++)lay [i]=0;
        vector <int> a(n),b(n);
        for(int i=1;i<=n-1;i++) cin >> a[i];
        for(int i=1;i<=n-1;i++) cin >> b[i];
        vector <pl> f;
        
        for(int i=0;i<m;i++){
            int x,y,z;
            cin >> x >> y >> z;
            f.push_back({x,y,z,ii});
            ii++;
        }
        sort(f.begin(),f.end(),cmp);
        int A=0,B=0;
        vector <int> can;
        for(auto i:f){
            int x=i.u,y=i.v;
            x=find(x);
            y=find(y);
            if(x==y) continue;
            add(x,y);
            if(i.w==2) B++;
            else {
                can.push_back(i.id);
                lay[i.id]=1;
            }
        }
        // for(auto i:can) cout << i << " ";
        reset(n);
        sort(f.begin(),f.end(),cmp2);
        for(auto i:f){
            int x=i.u,y=i.v;
            x=find(x);
            y=find(y);
            if(x==y) continue;
            add(x,y);
            if(i.w==1) A++;
        }
        int minn=INT_MAX,minx=0;
        for(int i=can.size();i<=A;i++) {
            if(a[i]+b[n-i-1]<minn){
                minn=a[i]+b[n-i-1];
                minx=i;
            }
        }
        reset(n);
        for(int id : can){
            for(auto &e : f){
                if(e.id == id){
                    add(e.u, e.v);
                    break;
                }
            }
        }
        for(auto &e : f){
            if((int)can.size() >= minx) break;
            if(e.w==1 && !lay[e.id] && find(e.u)!=find(e.v)){
                add(e.u,e.v);
                lay[e.id]=1;
                can.push_back(e.id);
            }
        }
        reset(n);
        for(int id : can){
            for(auto &e : f){
                if(e.id == id){
                    add(e.u, e.v);
                    break;
                }
            }
        }

        int needB = (n-1)-(int)can.size();
        for(auto &e : f){
            if(needB == 0) break;
            if(e.w==2 && !lay[e.id] && find(e.u)!=find(e.v)){
                add(e.u,e.v);
                lay[e.id]=1;
                can.push_back(e.id);
                needB--;
            }
        }
        for(auto i:can) cout << i<< " ";
    }
    
    return 0;
}