#include <bits/stdc++.h>
using namespace std;
struct pl{
    int l,r,id;
};
int n,c;
int a[300006];
pair <int, int >  st[1200005];
pair <int, int > merge(pair <int, int > a, pair <int, int > b){
    pair <int, int > z={0,0};
    if(a.second==0) return b;
    if(b.second==0) return a;
    if(a.first==b.first) {
        z.first=a.first;
        z.second=a.second+b.second;
        // return z;
    }
    else if(a.second>b.second){
        z.first=a.first;
        z.second=a.second-b.second;
        // return z;
    }
    else if(b.second>a.second){
        z.first=b.first;
        z.second=b.second-a.second;
        // return z;
    }
    
    return z;
}
void build(int id, int l, int r){
    if(l==r){
        st[id].first=a[l];
        st[id].second=1;
        // cout << l << " ";
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=merge(st[id*2],st[id*2+1]);
}
pair <int, int >  find(int id,int l, int r, int lf,int rt){
    if(rt<l||lf>r) return {0,0};
    if(lf<=l&&rt>=r) return st[id];
    int mid=(l+r)/2;
    pair <int, int > k1=find(id*2,l,mid,lf,rt),k2=find(id*2+1,mid+1,r,lf,rt);
    return merge(k1,k2);
}
vector <int> adj[10005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }
    build(1,0,n-1);
    int m; cin >> m;
    for(int i=1;i<=m;i++) {
        int l,r; cin >> l >> r;
        l--;r--;
        auto p=find(1,0,n-1,l,r);
        if(p.second==0){
            cout << "no\n";
            continue;
        }
        int c=upper_bound(adj[p.first].begin(),adj[p.first].end(),r)-lower_bound(adj[p.first].begin(),adj[p.first].end(),l);
        if(c>(r-l+1)/2) cout << "yes " << p.first << "\n";
        else cout << "no\n";
    }
    
    return 0;
}