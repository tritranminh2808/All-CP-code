#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q,m;
vector <int> adj[200005];
int stt[200005],ed[200005],valu[200005];
struct pl{
	int val,lazy;
};
pl st[800005];
long long ve[200005];
void build(int id, int l, int r){
	if(l==r){
		st[id].val=ve[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].val=st[id*2].val+st[id*2+1].val;
}
void push(int id, int l, int r){
    int mid=(l+r)/2;
    st[id*2+1].val+=st[id].lazy*(r-mid);
    st[id*2].val+=st[id].lazy*(mid-l+1);
    st[id*2+1].lazy+=st[id].lazy;
    st[id*2].lazy+=st[id].lazy;
    st[id].lazy=0;
}
void update(int id,int l,int r, int lf, int rt, int v){
	if(lf>r||rt<l) return;
	if(lf<=l&&rt>=r) {
		st[id].val+=v*(r-l+1);
        st[id].lazy+=v;
		return;
	}
    push(id,l,r);
	int mid=(l+r)/2;
	update(id*2,l,mid,lf,rt,v);
	update(id*2+1,mid+1,r,lf,rt,v);
	st[id].val=st[id*2].val+st[id*2+1].val;
}
int findi(int id, int l,int r, int lf, int rt){
	if(lf>r||rt<l) return 0;
	if(lf<=l&&rt>=r) return st[id].val;
    push(id,l,r);
	int mid=(l+r)/2;
	long long k1=findi(id*2,l,mid,lf,rt),k2=findi(id*2+1,mid+1,r,lf,rt);
	return k1+k2;
}
int timer=0;
void build_euler(int u, int v){
	stt[u]=++timer;
	ve[timer]=valu[u];
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
	for(int i=1;i<=n;i++) cin>> valu[i];
//	cout << find(1,1,n,1,n);
	build_euler(0,0);
    // for(int i=0;i<n;i++) cout << stt[i] << " " << ed[i] << "\n";
	build(1,1,n+1);
	while(q--){
		int qq;
		cin >> qq;
		if(qq==1){
			int u,v; cin >> u >> v;
			update(1,1,n+1,stt[u],ed[u],v);			
		}
		else if(qq==2){
			int k,u; cin >> k>> u;
			update(1,1,n+1,stt[k],stt[k],u);
		}
        else{
            int k; cin >> k;
            cout << findi(1,1,n+1,stt[k],ed[k]) << "\n";
        }
	}
	return 0;
}
