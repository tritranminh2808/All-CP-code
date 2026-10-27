#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ST[(const int)4e6+5];
int a[1000005];
void update(int id, int l, int r,int u,int v){
	if(u<l||u>r) return;
	if(l==r){
		ST[id]=v;
		return ;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	ST[id]=max(ST[2*id],ST[2*id+1]);
}
ll find(int id , int l, int r,int u,int v){
	if(u>r||v<l) return -8213621371;
	if(u<=l&&r<=v) return ST[id];
	int mid=(l+r)/2;
	ll min1=find(id*2,l,mid,u,v);
	ll min2=find(id*2+1,mid+1,r,u,v);
	return max(min1,min2);
}
int n,q,s;
signed main(){
	freopen("query.inp","r",stdin);
	freopen("query.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>q ;
	while(q--){
		char c;cin >> c;
		int a,b; cin >> a >> b;
		if(c=='S') update(1,1,n,a,b);
		else cout << find(1,1,n,a,b) << "\n";
	}
//	cout << s;
	return 0;
}
