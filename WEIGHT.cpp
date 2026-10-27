#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
int n,q;
struct pl{
    int tl,tr,idl,idr;
};
pl a[200005];
ll w[200005];
const int mod=998244353;
ll ans[200005],lw[200005],rw[200005];
void cok(int u, int p, bool turn){ //turn 0 la trai, turn 1 la phai
	// cout << u << " " << a[u].idl << " "<< a[u].idr << "\n";
	if(a[u].tl==1) lw[u]=w[a[u].idl]%mod;
	else cok(a[u].idl,u,0);
	if(a[u].tr==1) rw[u]=w[a[u].idr]%mod;
	else cok(a[u].idr,u,1);
	if(!turn) lw[p]=max(lw[u],rw[u])*2%mod;
	else rw[p]=max(lw[u],rw[u])*2%mod;
}
signed main(){
	freopen("weight.inp","r",stdin);
	freopen("weight.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   cin >> n >> q;
//    int 
   for(int i=1;i<=n;i++){
        char c; cin >> c;
        if(c=='S') a[i].tl=0;
        else a[i].tl=1;
        cin>> a[i].idl;
        char c2; cin >> c2;
        if(c2=='S') a[i].tr=0;
        else a[i].tr=1;
        cin >> a[i].idr;
   }
    for(int i=1;i<=n+1;i++) cin >> w[i];
	// for(inti=1)
   cok(1,0,-1);
   for(int i=1;i<=n;i++) ans[i]=max(lw[i],rw[i])*2%mod;
//    for(int i=1;i<=n;i++) cout << ans[i] << '\n';
    while(q--){
		int kk; cin >> kk;
		if(kk==2){
			int x;cin >> x;
			cout << ans[x]%mod << "\n";
		}
		else {
			int u;
			ll v; cin >> u >> v;
			w[u]=v;
			cok(1,0,-1);
			for(int i=1;i<=n;i++) ans[i]=max(lw[i],rw[i])*2%mod;
		}
	}
    return 0;
}