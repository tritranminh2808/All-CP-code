#include <bits/stdc++.h>
using namespace std;
struct pl{
    int l,r,id;
};
pl q[200005];
int n;
bool cmp(pl x, pl y){
    return x.l < y.l;
}
int a[30005],nxt[30005],cur[1000005];  
int st[1000005],res[200005];
void update(int i, int v){
    for(;i<=n;i+=i&-i) st[i]+=v;
}
int find(int i){
    int s=0;
    for(;i>0;i-=i&-i) s+=st[i];
    return s;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=n;i>=1;i--){
        nxt[i]=cur[a[i]];
        cur[a[i]]=i;
    }
    int Q; cin >> Q;
    for(int i=1;i<=Q;i++){
        int l,r; cin >> l >> r;
        q[i]={l,r,i};
    }
    sort(q+1,q+Q+1,cmp);
    memset(cur,0,sizeof(cur));
    for(int i=q[1].l;i<=n;i++){
        if(cur[a[i]]==0) update(i,1);
        cur[a[i]]=1;
    }
    res[q[1].id]=find(q[1].r)-find(q[1].l-1);
    for(int i=2;i<=Q;i++) {
        for(int j=q[i-1].l;j<q[i].l;j++){
            if(nxt[j])update(nxt[j],1);
            update(j,-1);
        }
        res[q[i].id]=find(q[i].r)-find(q[i].l-1);
    }
    for(int i=1;i<=Q;i++) cout << res[i] << "\n";
    return 0;
}