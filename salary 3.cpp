#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q,m;
vector <int> adj[200005];
int stt[200005],ed[200005],val[200005];
long long st[800005],ve[200005];
void build(int id, int l, int r){
	if(l==r){
		st[id]=ve[l];
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
int timer=0;
void build_euler(int u, int v){
	stt[u]=++timer;
	ve[timer]=val[u];
	for(auto i:adj[u]){
		if(i==v) continue;
		build_euler(i,u);
	}
	ed[u]=timer;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
    for(int i=1;i<=n;i++){
        int u;cin >> u;
        adj[u].push_back(i);
    }
	for(int i=1;i<=n;i++) cin>> val[i];
//	cout << find(1,1,n,1,n);
	build_euler(0,0);
    // for(int i=0;i<n;i++) cout << stt[i] << " " << ed[i] << "\n";
	build(1,1,n+1);
	while(q--){
		int qq;
		cin >> qq;
		if(qq==1){
			int u,v; cin >> u >> v;
            int k=find(1,1,n+1,stt[u],stt[u]);
			update(1,1,n+1,stt[u],k+v);			
		}
		else{
			int k; cin >> k;
			cout << find(1,1,n+1,stt[k],ed[k]) << "\n";
		}
	}
	return 0;
}
