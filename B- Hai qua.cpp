#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
int n,k;
struct pl{
    int lf, rt,maxx,sum;  
};
pl st[1200005];
int a[300005],typ[300005];
pl merge(pl x, pl y){
    pl z;
    z.lf=max(x.sum+y.lf,x.lf);
    z.rt=max(y.sum+x.rt,y.rt);
    z.maxx=max({x.maxx,y.maxx,x.rt+y.lf});
    z.sum=x.sum+y.sum;
    return z;
}
void build(int id,int l, int r){
    if(l==r){
        st[id].maxx=a[l];
        st[id].lf=a[l];
        st[id].rt=a[l];
        st[id].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=merge(st[id*2],st[id*2+1]);
}
void update(int id,int l, int r, int u, int v){
    if(u<l||u>r) return;
    if(l==r){
        st[id].maxx=v;
        st[id].lf=v;
        st[id].rt=v;
        st[id].sum=v;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    st[id]=merge(st[id*2],st[id*2+1]);
}
pl find(int id,int l,int r, int u, int v){
    if(u>r||v<l) return {0,0,0};
    if(u<=l&&v>=r) return st[id];
    int mid=(l+r)/2;
    return merge(find(id*2,l,mid,u,v),find(id*2+1,mid+1,r,u,v));
}

vector <pair <int, int > > qua[300005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>> n >>k;
    for(int i=1;i<=n;i++) cin >> typ[i];
    for(int i=1;i<=n;i++) cin>> a[i];
    build(1,1,n);
    for(int i=1;i<=n;i++) qua[typ[i]].push_back({a[i],i});
    int sol=0;
    for(int i=1;i<=k;i++){
        for(auto j:qua[i]){
            update(1,1,n,j.second,-(k-1)*j.first);
        }
        sol=max(sol,find(1,1,n,1,n).maxx);
        for(auto j:qua[i]){
            update(1,1,n,j.second,j.first);
        }
    }
    cout << sol;
    return 0;
}
