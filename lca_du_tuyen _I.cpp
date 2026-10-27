#include <bits/stdc++.h>
using namespace std;
int n,val[200005],stt[200005],ed[200005];
vector <int> adj[200005];
vector <int> b;
void nen(){
    for(int i=1;i<=n;i++) b.push_back(val[i]);
    unordered_map<int, int> mp;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=0;i<b.size();++i) mp[b[i]]=i+1;
    for(int i=1;i<=n;i++) val[i]=mp[val[i]];
}
int timer=0;
vector <int> euler;
void dfs(int u,int v){
    stt[u]=++timer;
    euler.push_back(u);
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
        // euler.push_back(u);
    }
    ed[u]=timer;
}
int a[200005];
struct pl{
    int l,r,id;
};
vector <pl> q;
int sqr;
bool cmp(pl x, pl y){
    if(x.l/sqr==y.l/sqr) return x.r<y.r;
    return x.l<y.l;
}
int cnt[200005];
int sol[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    sqr=sqrt(n);
    for(int i=1;i<=n;i++) cin >> val[i];
    nen();
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int i=1;i<=n;i++) cout << val[i] << " ";
    dfs(1,0);
    for(int i=0;i<n;i++){
        q.push_back({stt[euler[i]],ed[euler[i]],euler[i]});
        a[i+1]=val[euler[i]];
    }
    sort(q.begin(),q.end(),cmp);
    int ans=0;
    for(int i=q[0].l;i<=q[0].r;i++) {
        cnt[a[i]]++;
        if(cnt[a[i]]==1) ans++;
    }
    // for(int i=0;i<n;i++) cout << q[i].l << " " << q[i].r << " " << q[i].id << "\n";
    // for(int i=1;i<=n;i++)cout << a[i] << " ";
    cout << endl;
    sol[q[0].id]=ans;
    for(int i=1;i<n;i++){
        // cout << q[i].l << " " << q[i].r  << " " << q[i].id << "\n";
        if(q[i].l<q[i-1].l){
            for(int j=q[i].l;j<q[i-1].l;j++) {
                cnt[a[j]]++;
                if(cnt[a[j]]==1) ans++; 
            }
        }
        if(q[i].l>q[i-1].l){
            for(int j=q[i-1].l;j<q[i].l;j++) {
                cnt[a[j]]--;
                if(cnt[a[j]]==0) ans--;
            }
        }
        if(q[i].r<q[i-1].r){
            for(int j=q[i].r+1;j<=q[i-1].r;j++) {
                cnt[a[j]]--;
                if(cnt[a[j]]==0) ans--;
            }
        }
        if(q[i].r>q[i-1].r){
            for(int j=q[i-1].r+1;j<=q[i].r;j++){
                cnt[a[j]]++;
                if(cnt[a[j]]==1) ans++;
            }
        }
        sol[q[i].id]=ans;
    }
    for(int i=1;i<=n;i++) cout << sol[i] << " ";
    return 0;
}