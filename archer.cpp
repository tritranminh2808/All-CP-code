#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int c=257;
const int mod=1e9+7;
struct pl{
	int x,y,z;
};
pl a[20005];
bool cmp(pl p,pl q){
	if(p.x==q.x){
		if(p.y==q.y) return p.z<q.z;
		return p.y<q.y;
	}
	return p.x<q.x;
}
int codee(int x, int y, int z){
	return	(((x+1)%mod*c+y+1)*c%mod+z+1)*c%mod;
}
int sol=1;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("archer.inp","r",stdin);
//	freopen("archer.out","w",stdout);
	unordered_map<int, int> cnt,f;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		int k=codee(a[i].x,a[i].y,a[i].z);
		cnt[k]++;
	}
	if(cnt.size()==1) {
		cout << n;
		return 0;
	}
//	cout << cnt.size();
	sort(a+1,a+n+1,cmp);
	unordered_map<int,bool> vsti;
	for(int i=1;i<=n;i++){
		int gg=codee(a[i].x,a[i].y,a[i].z);
		if(vsti[gg]==1)  continue;
		vsti[gg]=1;
		f.clear();
		unordered_map<int,bool> vst;
		for(int j=1;j<i;j++){
			int gx=codee(a[j].x,a[j].y,a[j].z);
			if(vst[gx]==1)  continue;
			vst[gx]=1;
//			if(a[j].z<=0) continue;
			int d1=a[i].x-a[j].x,d2=a[i].y-a[j].y,d3=a[i].z-a[j].z;
			if(d3<=0) continue;
			int g=__gcd(__gcd(abs(d1),abs(d2)),abs(d3));
			d1/=g;d2/=g;d3/=g;
			int k=codee(d1,d2,d3);
//			int sech=codee(a[i].x,a[i].y,a[i].z);
			f[k]+=cnt[gg];
			sol=max(sol,f[k]+1);
		}
//		cout << sol << "\n";
	}
	cout << sol;
	return 0;
	
}
