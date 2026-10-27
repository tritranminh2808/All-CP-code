#include <bits/stdc++.h>
#define int long long
using namespace std;
int limit, n;
int a[100005];
int se=0;
bool cmp(pair <int, int > a, pair <int, int > b){
	return a.first+a.second*se<b.first+b.second*se;
}
bool check(int e){
	int x=limit,dem=0;
	vector < pair <int, int > > v;
	for(int i=1;i<=n;i++) v.push_back({a[i],i});
	se=e;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++){
		x-=v[i].first+v[i].second*e;
		if(x<0) break;
		dem++;
	}
	if(dem>=e) return true;
	return false;
}
int sol=0,res=0;
signed main(){
	cin >> n >> limit;
	for(int i=1;i<=n;i++) cin >> a[i];
//	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)/2;
//		cout << mid << endl;
		if(check(mid)) {
			l=mid+1;
			sol=mid;
		}
		else r=mid-1;
	}
	cout << sol << " ";
	se=sol;
	if(sol==0) return 0;
	vector < pair <int, int > > v;
	for(int i=1;i<=n;i++) v.push_back({a[i],i});
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<sol;i++) res+=v[i].first+v[i].second*sol;
	cout << res;
	return 0;
}
