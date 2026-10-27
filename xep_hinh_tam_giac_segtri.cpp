#include <bits/stdc++.h>
// #define int long long
using ll=long long;
using namespace std;
int a[300005];
int st[11][1200005];
void update(int x,int id, int l, int r, int u, int v){
    if(u<l||u>r) return;
    if(l==r){
        st[x][id]=v;
        return;
    }
    int mid=(l+r)/2;
    update(x,id*2,l,mid,u,v);
    update(x,id*2+1,mid+1,r,u,v);
    st[x][id]=st[x][id*2]+st[x][id*2+1];
}
int find(int x , int id, int l, int r, int lf, int rt){
    if(lf>r||rt<l) return 0;
    if(lf<=l&&rt>=r) return st[x][id];
    int mid=(l+r)/2;
    int k1=find(x,id*2,l,mid,lf,rt),k2=find(x,id*2+1,mid+1,r,lf,rt);
    return k1+k2;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        update(a[i],1,1,n,i,1);
    }
    while(m--){
        int cc; cin >> cc;
        if(cc==1){
            int u,v; cin >> u >> v;
            update(a[u],1,1,n,u,0);
            update(v,1,1,n,u,1);
            a[u]=v;
        }
        else{
            int l,r; cin >> l >> r;
            ll sol=0;
            for(int i=1;i<=10;i++){
                //3 canh deu bang i neu du canh
                ll k=find(i,1,1,n,l,r);

                if(k>=3) sol+=(k-2)*(k-1)*k/6;
                //2 canh dau bang i, bo ba la (i,i,j)
                for(int j=i+1;j<=10;j++){
                    if(j>=i*2) break;
                    if(k>=2)sol+=(k-1)*k/2*find(j,1,1,n,l,r);
                }
                // canh 1 la i, canh 2 la j
                for(int j=i+1;j<=10;++j){
                    //bo ba la i,j,j
                    ll k2=find(j,1,1,n,l,r);
                    if(k2>=2) sol+=k*(k2-1)*k2/2;
                    //bo ba la i,j,p
                    for(int p=j+1;p<=10;++p) {
                        if(p>=i+j) break;
                        ll k3=find(p,1,1,n,l,r);
                        sol+=k*k2*k3;
                    }
                }
            }
            cout << sol << "\n";
        }

    }
    return 0;
}