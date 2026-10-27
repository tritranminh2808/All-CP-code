#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
pair <int, int > st[800005];
priority_queue<int, vector <int> , greater <int> > pq[200005];
void update(int id, int l , int r, int u){
    if(u<l||u>r) return ;
    if(l==r){
        if(pq[u].empty()) st[id]={-1e16,u};
        else st[id]={pq[u].top(),u};
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u);
    update(id*2+1,mid+1,r,u);
    if(st[id*2]>st[id*2+1]) st[id]=st[id*2];
    else st[id]=st[id*2+1];
}
pair <int, int > find(int id, int l, int r, int lf, int rt){
    if(lf>r||rt<l) return {-1e16,-1};
    if(lf<=l&&rt>=r) return st[id];
    int mid=(l+r)/2;
    pair <int, int > k1=find(id*2,l,mid,lf,rt);
    pair <int, int > k2=find(id*2+1,mid+1,r,lf,rt);
    if(k1.first>k2.first) return k1;
    else return k2;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q >> n;
    while(q--){
        int ty; cin >> ty;
        if(ty==1){
            int t,w; cin >> t >> w;
            pq[t].push(w);
            update(1,1,n,t);
        }
        else{
            auto f=find(1,1,n,1,n);
            cout << f.first << "\n";
            if(!pq[f.second].empty()) pq[f.second].pop();
            update(1,1,n,f.second);
        }
    }
    return 0;
}