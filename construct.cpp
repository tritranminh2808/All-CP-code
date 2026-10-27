#include <bits/stdc++.h>
using namespace std;
struct node {
    int minn, val,lazy;
};
node st[4000005];
int a[1000005];
void build(int id, int l, int r){
    if(l==r){
        st[id].minn=a[l];
        st[id].val=a[l];
        st[id].lazy=0;
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].minn=min(st[id*2].minn,st[id*2+1].minn);
    st[id].val=st[id*2].val+st[id*2+1].val-st[id].minn;
}
void push(int id, int l,int r){
    int mid=(l+r)/2;
    st[2*id].val+=st[id].lazy*(mid-l);
    st[2*id+1].val+=st[id].lazy*(r-mid-1);
    st[id*2].lazy+=st[id].lazy;
    st[id*2+1].lazy+=st[id].lazy;
    st[id*2].minn+=st[id].lazy;
    st[id*2+1].minn+=st[id].lazy;
    st[id].lazy=0;
}
void update(int id, int l,int r, int lf,int rt ,int k){
    if(lf>r||rt<l) return;
    if(lf<=l&&rt>=r){
        st[id].val+=(r-l+1)*k;
        st[id].minn+=k;
        st[id].lazy+=k;
        return;
    }
    push(id,l,r);
    int mid=(l+r)/2;
    update(id*2,l,mid,lf,rt,k);
    update(id*2+1,mid+1,r,lf,rt,k);
    st[id].minn=min(st[id*2].minn,st[id*2+1].minn);
    st[id].val=st[id*2].val+st[id*2+1].val-st[id].minn;
}
pair <int, int >  find(int id, int l,int r, int lf,int rt ){
    if(lf>r||rt<l) return {0,INT_MAX};
    if(lf<=l&&rt>=r)return {st[id].val,st[id].minn};
    push(id,l,r);
    int mid=(l+r)/2;
    auto k1=find(id*2,l,mid,lf,rt);
    auto k2=find(id*2+1,mid+1,r,lf,rt);
    return {k1.first+k2.first-min(k1.second,k2.second),min(k1.second,k2.second)};
}
void xuat(int id, int l, int r){
    if(l==r){
        cout << l << " " << r << " " << st[id].val << "\n";
        return;
    }
    push(id,l,r);
    int mid=(l+r)/2;
    xuat(id*2,l,mid);
    xuat(id*2+1,mid+1,r);
    cout << l << " " << r << " " << st[id].val << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        for(int i=0;i<=4*n;++i){
            st[i].val=0;
            st[i].minn=INT_MAX;
            st[i].lazy  = 0;
        }
        for(int i=1;i<=n;i++) cin>> a[i];
        build(1,1,n);
        while(m--){
            int typ=0;cin >> typ;
            if(typ==1){
                int l,r,k; cin >> l >> r >> k;
                update(1,1,n,l,r,k);
                xuat(1,1,n);
            }
            else{
                int l,r; cin >> l >> r;
                pair <int, int > sol=find(1,1,n,l,r);
                cout << sol.first << "\n";
            }
        }
    }
    return 0;
}