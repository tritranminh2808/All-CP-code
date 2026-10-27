#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005];
int n,k;
void sub1(){
	int ans=0;
	for(int i=n;i>=1;i-=k) {
		int minn=a[i-k+1];
		for(int j=i;j>=i-k+1;j--) b[j]=minn;
	}
	for(int i=1;i<=k;i++) {
		b[i]=a[1];
		ans+=b[i];
	}
	cout << ans;
	exit(0);
}

signed main(){
	freopen("array.inp","r",stdin);
	freopen("array.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin>> a[i];
    if(is_sorted(a+1,a+n+1)) sub1();
	for(int i=1;i<=n;i++) b[i]=INT_MAX;
	for(int i=1;i<=n-k+1;++i){
		if(b[i]>a[i]){
			int minn=INT_MAX;
			for(int j=i;j<=i+k-1;j++) minn=min(minn,a[j]);
			for(int j=i;j<=i+k-1;j++) b[j]=minn; 
		}
	}
	int x=n/k;
	x=x*k;
	int minn=INT_MAX;
	for(int i=n-k+1;i<=n;i++) minn=min(minn,a[i]);
	for(int i=n-k+1;i<=n;i++) b[i]=minn;
	int ans=0;
	for(int i=1;i<=n;i++) ans+=b[i];
	cout << ans;
    return 0;
}