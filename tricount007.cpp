#include <bits/stdc++.h>
using namespace std;
long long r=0;
int main()
{
//	freopen("TRICOUNT007.INP","r",stdin);
//	freopen("TRICOUNT007.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n; int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			r+=lower_bound(a+j+1,a+n,a[i]+a[j])-a-j-1;
		}
	}
	cout << r;
	return 0;
}
