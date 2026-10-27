#include <bits/stdc++.h>
#define int long long
using namespace std;
const int pp=1e6+5;
int st[4*pp];
int a[pp],dp[pp];
int n;
int l,r;
void update(int id, int l, int r, int u, int v){
    if(u<l||u>r) return;
    if(l==r) {
        st[id]=v;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    st[id]=max(st[id*2],st[id*2+1]);
}
int find(int id,int l,int r, int lf, int rt){
    if(lf>r||rt<l) return 0;
    if(lf<=l&&rt>=r) return st[id];
    int mid=(l+r)/2;
    return max(find(id*2,l,mid,lf,rt),find(id*2+1,mid+1,r,lf,rt));
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
        int lf=max((int)0,i-r),rt=max((int)0,i-l);
        int x=find(1,1,n,lf,rt);
        dp[i]+=x;
        update(1,1,n,i,dp[i]);
    }
    int sol=0;
    for(int i=1;i<=n;++i) sol=max(sol,dp[i]);
    cout << sol;
    return 0;
}