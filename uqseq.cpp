#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll st[4000005];
void update(int id, int l, int r, int lf, int rt,int val){
	if(rt<l||lf>r) return;
	if(lf<=l&&rt>=r) {
		st[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,lf,rt,val);
	update(id*2+1,mid+1,r,lf,rt,val);
//	st[id]=st[id*2]+st[id*2+1];
}
ll find(int id,int l ,int r , int u){
	if(u<l||u>r) return 0;
	if(l==r) return st[id];
	ll mid=(l+r)/2;
	ll x1=find(id*2,l,mid,u),x2=find(id*2+1,mid+1,r,u);
	return st[id]+x1+x2;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("uqseq.inp","r",stdin);
	freopen("uqseq.out","w",stdout);
	int n,t; cin >>n>> t;
	while(t--){
		char c; cin >> c;
		if(c=='I') {
			int l,r,u; cin >> l >> r >> u;
			update(1,1,n,l,r,u);
		}
		else {
			int q; cin>> q;
			cout << (ll)find(1,1,n,q) << "\n";
		}
		
	}
	return 0;
}
