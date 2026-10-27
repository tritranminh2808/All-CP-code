#include <bits/stdc++.h>
using namespace std;

vector<pair <int,int> > adj[1000005];
int n,q,s;
long long kc[1000005];
// int st[400005];
int o1=0,o2=0;
void build(int id, int l, int r){
    if(l==r){
        adj[id+o1].push_back({l,0});
        return;
    }
    int mid=(l+r)/2;
    adj[id+o1].push_back({o1+id*2,0});
    adj[id+o1].push_back({o1+id*2+1,0});
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}
void bui(int id, int l, int r){
    if(l==r){
        adj[l].push_back({id+o2,0});
        return;
    }
    int mid=(l+r)/2;
    adj[o2+id*2].push_back({o2+id,0});
    adj[id*2+1+o2].push_back({o2+id,0});
    bui(id*2,l,mid);
    bui(id*2+1,mid+1,r);
}
void update(int id,int l, int r, int u,int lf, int rt, int w){
    if(lf>r||rt<l) return;
    if(lf<=l&&rt>=r){
        adj[u].push_back({o1+id,w});
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,lf,rt,w);
    update(id*2+1,mid+1,r,u,lf,rt,w);
}
void update2(int id, int l,int r, int u,int lf, int rt, int w){
    if(lf>r||rt<l) return;
    if(lf<=l&&rt>=r){
        adj[o2+id].push_back({u,w});
        return;
    }
    int mid=(l+r)/2;
    update2(id*2,l,mid,u,lf,rt,w);
    update2(id*2+1,mid+1,r,u,lf,rt,w);
}
void dijkstra(int u){
    priority_queue<pair<long long, int> , vector <pair <long long ,int> >, greater<pair <long long ,int> >  >pq;
    pq.push({0,u});
    kc[u]=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        if(kc[p.second]<p.first) continue;
        for(auto i:adj[p.second]){
            if(p.first+i.second<kc[i.first]){
                kc[i.first]=p.first+i.second;
                pq.push({kc[i.first],i.first});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>> n >> q >> s;
    o1=n;
    o2=5*n;
    for(int i=1;i<=n*10;i++) kc[i]=1e16;
    build(1,1,n);
    bui(1,1,n);
    for(int i=1;i<=q;i++){
        int ty;cin >> ty;
        if(ty==1){
            int x,y;
            long long l; cin >> x >> y >> l;
            adj[x].push_back({y,l});
            // adj[y].push_back({1,x,x,l});
        }
        else if(ty==2){
            int x,y,lf,rt;
            long long l;
            cin >> x >> lf >> rt >> l;
            update(1,1,n,x,lf,rt,l);
        }
        else{
            int x,y,lf,rt;
            long long l;
            cin >> x >> lf >> rt >> l;
            update2(1,1,n,x,lf,rt,l);
        }
    }
    dijkstra(s);
    for(int i=1;i<=n;i++) {
        if(kc[i]==1e16) cout << "-1 ";
        else cout << kc[i] << " ";
    }
    return 0;
}