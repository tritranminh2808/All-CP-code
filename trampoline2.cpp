#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[200009],st[800009],cnt;
void update(int id,int l,int r,int u, int v,int val) {
    if (v<l||r<u) return;
    if (u<=l&&r<=v){
        st[id]+=val;
        return;
    }
    int m=(l + r)/2;
    update(id*2,l,m,u,v,val);
    update(id*2+1,m+1,r,u,v,val);
    st[id]=st[id*2]+st[id*2+1];
}
int sum(int id,int l,int r,int u){
    if(u<l||r<u) return 0;
    if(l==r) return st[id];
    int m=(l+r)/2;
    return st[id]+sum(id*2,l,m,u)+sum(id*2+1,m+1,r,u);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;cnt=0;
        fill(st,st+4*n+1,0);
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i){
            if(a[i]+sum(1,1,n,i)>=2){
                int v=sum(1,1,n,i)-a[i]+1;
                update(1,1,n,i,i,-v);
                update(1,1,n,i+1,i+1,2*v);
                update(1,1,n,i+2,i+2,-v);
            }
            cnt+=a[i]-sum(1,1,n,i)-1;
            update(1,1,n,i+2,min(i+a[i],n),1);
        }
        cout<<cnt<<"\n";
    }
}

