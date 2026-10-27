#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
int n,m;
struct pl{
	int f,s,id;
	inline bool operator < (const pl &b ) const{
		return s*b.f<b.s*f;
	}
};
pl a[100005];
//int l,r; 
bool cmp(pl a, pl b){
	return a.s*b.f<b.s*a.f;
}
int vt[100005];
int pr[100005],prefix[100005],pretime[100005],prephat[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i].f;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++) cin >> a[i].s;
	sort(a+1,a+1+n,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i].s;
		pr[i]=cnt*a[i].f;
		prefix[i]=prefix[i-1]+pr[i];
		vt[a[i].id]=i;
		prephat[i]=prephat[i-1]+a[i].f;
		pretime[i]=pretime[i-1]+a[i].s;
	}
//	for(int i=1;i<=n;i++) cout << prefix[i] << " ";
	while(m--){
		int x,y; cin >> x >> y;
//		cout << j << " " << i << "\n";
		int i=vt[y],j=vt[x];
		if(j<i){
			cout << prefix[n] << "\n";
			continue;
		}
		
		ll sol=prefix[n];
		sol-=pretime[i] * a[i].f + pretime[j] * a[j].f;
		
		sol-=(prephat[j-1] - prephat[i]) * a[i].s;
		
		pl z={a[j].f + a[i].f , a[j].s + a[i].s , 0};
		
		auto k=upper_bound(a+i+1 , a+j , z) - a;
		
		sol+=z.s*(prephat[j-1]-prephat[k-1]);
		
		sol+=(pretime[k-1]-a[i].s+z.s)*z.f;
		
		sol-=a[j].f*a[i].s;
		cout << sol << "\n";
	}
	return 0;
}

