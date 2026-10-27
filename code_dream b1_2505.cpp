#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5005],b[5005];long long f[5005][5005];
long long res=-1e18;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=max(f[i-1][j-1]+a[i]*b[j],a[i]*b[j]);
			res=max(res,f[i][j]);
		}
	}
	cout << res;
	return 0;
}
