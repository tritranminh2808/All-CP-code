#include <bits/stdc++.h>
using namespace std;
using ll= long long;

struct sechtree{
	ll n;
	vector <pair <ll,ll> > st;
	sechtree(int sz){
		n=sz;
		st.resize(4*n,{0,0});
	}
	pair <ll,ll> merge(pair <ll,ll> x, pair <ll,ll> y) {
		pair <ll,ll> gay;
		if(x.first>y.first){
			gay.first=x.first;
			if(y.first>x.second) gay.second=y.first;
			else gay.second=x.second;
		}
		else{
			gay.first=y.first;
			if(x.first>y.second) gay.second=x.first;
			else gay.second=y.second;
		}
		return gay;
	}
	void build(vector <ll> &a, int id, int l, int r){
		if(l==r) {
			st[id]={a[l],-1e18};
			return;
		}
		int mid=(l+r)/2;
		build(a,id*2,l,mid);
		build(a,id*2+1,mid+1,r);
		st[id]=merge(st[id*2],st[id*2+1]);
	}
	pair<ll,ll> find(int id, int l, int r, int lf, int rt){
		if(lf>r||rt<l) return {-1e18,-1e18};
		if(lf<=l&&rt>=r) return st[id];
		int mid=(l+r)/2;
		pair <ll,ll> k1=find(id*2,l,mid,lf,rt),k2=find(id*2+1,mid+1,r,lf,rt);
		return merge(k1,k2);
	}
}; 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> a;
	int n,q; cin>> n >> q;
	a.resize(n+1,0);
	sechtree st(n);
	for(int i=1;i<=n;i++) cin >> a[i];
	st.build(a,1,1,n);
	while(q--){
		int u,v; 
		cin >> u >> v;
		cout << st.find(1,1,n,u,v).second << "\n";
	}
}
