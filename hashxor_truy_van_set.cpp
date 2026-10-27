#include <bits/stdc++.h>
using namespace std;
struct pl{
    int l,r,id;
};
pl qa[200005],qb[200005];
int n;
bool cmp(pl x, pl y){
    return x.l < y.l;
}
int a[200005],b[200005],nxt[400005],cur[400005],nxt2[400005],cur2[400005];  
int st[400005],res[200005],sol[200005];
// unordered_map<long long, int> newv; 
void nen(){
    vector <int> c;
    for(int i=1;i<=n;i++) {
        c.push_back(a[i]);
        c.push_back(b[i]);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(int i=1;i<=n;i++) {
        a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin()+1;
        b[i]=lower_bound(c.begin(),c.end(),b[i])-c.begin()+1;
    }
}
void update(int i, int v){
    for(;i<=n;i+=i&-i) st[i]+=v;
}
int find(int i){
    int s=0;
    for(;i>0;i-=i&-i) s+=st[i];
    return s;
}
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long ran(int l, int r){
    return l+rng()%(r-l+1);
}
unordered_map<int, long long > newv;
unordered_map<long long,bool> se;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=400000;i++){
        long long cc=ran(1,1e18);
        while(se[cc]==1)    cc=ran(1,1e18);
        newv[i]=cc;
        se[cc]=1;
    }
    nen();
    for(int i=n;i>=1;i--){
        nxt[i]=cur[a[i]];
        nxt2[i]=cur2[b[i]];
        // cur[a[i]]=i;
    }
    int Q; cin >> Q;
    for(int i=1;i<=Q;i++){
        int l,r,u,v; cin >> l >> r >> u >> v;
        qa[i]={l,r,i};
        qb[i]={l,r,i};
    }
    sort(qa+1,qa+Q+1,cmp);
    sort(qb+1,qb+Q+1,cmp);
    memset(cur,0,sizeof(cur));
    for(int i=qa[1].l;i<=n;i++){
        if(cur[a[i]]==0) update(i,1);
        cur[a[i]]=1;
    }
    res[qa[1].id]=find(qa[1].r)-find(qa[1].l-1);
    for(int i=2;i<=Q;i++) {
        for(int j=qa[i-1].l;j<qa[i].l;j++){
            if(nxt[j])update(nxt[j],1);
            update(j,-1);
        }
        res[qa[i].id]=find(qa[i].r)-find(qa[i].l-1);
    }

    for(int i=0;i<=400000;++i) st[i]=0;
    memset(cur2,0,sizeof(cur2));
    for(int i=qb[1].l;i<=n;i++){
        if(cur2[b[i]]==0) update(i,1);
        cur2[b[i]]=1;
    }
    sol[qb[1].id]=find(qb[1].r)-find(qb[1].l-1);
    for(int i=2;i<=Q;i++) {
        for(int j=qb[i-1].l;j<qb[i].l;j++){
            if(nxt2[j])update(nxt2[j],1);
            update(j,-1);
        }
        sol[qb[i].id]=find(qb[i].r)-find(qb[i].l-1);
    }
    
    
    return 0;
}