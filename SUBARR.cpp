#include <bits/stdc++.h>
using namespace std;
long long res=-99,m;
int main ()
{
	freopen("SUBARR.inp","r",stdin);
	freopen("SUBARR.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		m=0;
		for(int j=i;j<n;j++){
			if(a[j]%a[i]==0) m++;
		}
		res=max(res,m);
	}
	cout << res;
	return 0;
}
