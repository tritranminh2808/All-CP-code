#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
int n,k;
bool check(int mid){
	int sum=0,dem=0;
	for(int i=1;i<=n;i++){
		if(a[i]>mid) return false;
		sum+=a[i];
		if(sum>mid) {
			dem++;
			sum=a[i];
		}
	}
	dem++;
	if(dem<=k) return true;
	return false;
}
signed main(){
	 cin >> n >> k;
	int l=-1e18,r=0;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		r+=a[i];
		l=max(l,a[i]);
	}
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		
		else l=mid+1;
	}
	cout << l;
}
