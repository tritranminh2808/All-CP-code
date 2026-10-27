#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
int n,m,q;
int a[1005][1005],pr[1005][1005];
struct pl{
	int cnt,ts,ms,id;
};
int lowerbound(int i,int u){
	int l=1,r=m;
	while(l<=r){
		int mid=(l+r)/2;
		if(pr[i][mid]>u) r=mid-1;
		else l=mid+1;
	}
	return l-1;
}
bool cmp(pl x, pl y){
	if(x.cnt==y.cnt){
//		if(x.ts*y.ms==x.ms*y.ts&&x.ts*y.ms==0) return 
		if(x.ts*y.ms==x.ms*y.ts) return x.id < y.id;
		return  x.ts*y.ms>x.ms*y.ts;
	}
	return x.cnt>y.cnt;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			cin >> a[i][j];
			pr[i][j]=pr[i][j-1]+a[i][j];
		}
	}
	while(q--){
		ll u; cin>> u;
		vector <pl> lod(n+1);
		for(int i=1;i<=n;i++){
			ll k=0,h=u;
			if(u>pr[i][m]){
				k=u/pr[i][m]*m;
				h=u%pr[i][m];
			}
			int it=lowerbound(i,h);
			k+=it;
			lod[i].cnt=k;
			lod[i].ts=h-pr[i][it];
			if(it+1<=n)lod[i].ms=a[i][it+1];
			else lod[i].ms=a[i][1];
			lod[i].id=i;
//			cout << lod[i].cnt << " " << lod[i].ts << " " << lod[i].ms<< " " << lod[i].id<< endl;
		}
		sort(lod.begin()+1,lod.end(),cmp);
		/*for(int i=1;i<=n;i++){
			cout << lod[i].cnt << " " << lod[i].ts << " " << lod[i].ms<< " " << lod[i].id<< endl;
		}*/
		cout << lod[1].id<< "\n";
	}
	return 0;
}
