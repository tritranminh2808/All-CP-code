#include <bits/stdc++.h>
using namespace std;
int n,val[200005],stt[200005],ed[200005];
vector <int> adj[200005];
vector <int> b;
int timer=0;
vector <int> euler;
void dfs(int u,int v){
    stt[u]=++timer;
    euler.push_back(u);
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
        euler.push_back(u);
    }
    ed[u]=timer;
}
int a[200005];
struct pl{
    int l,r,id;
};
vector <pl> q;
int sqr;
int cnt[200005],sol[200005],fir[200005],st[800005];
int Q;
void build(int id, int l, int r){
	if(l==r){
		st[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=st[id*2]+st[id*2+1];
}
void update(int id,int l,int r, int u, int v){
	if(u<l||u>r) return;
	if(l==r) {
		st[id]=v;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	st[id]=st[id*2]+st[id*2+1];
}
long long find(int id, int l,int r, int lf, int rt){
	if(lf>r||rt<l) return 0;
	if(lf<=l&&rt>=r) return st[id];
	int mid=(l+r)/2;
	long long k1=find(id*2,l,mid,lf,rt),k2=find(id*2+1,mid+1,r,lf,rt);
	return k1+k2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> Q;

    map<pair <int, int > ,int> mp;
    for(int i=1;i<n;i++){
        int u,v,x; cin >> u >> v >> x;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}]=x;
        mp[{v,u}]=x;
    }
    dfs(1,0);
    int sz=euler.size();
    fir[1]=1;
    for(int i=1;i<sz;i++) {
        int x=euler[i];
        if(fir[x]==0) fir[x]=i+1;
        a[i+1]=mp[{euler[i-1],euler[i]}];
    }
    for(int i=1;i<=sz;i++) cout << a[i] << " ";
    return 0;
}