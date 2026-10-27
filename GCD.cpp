#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005];
int n,m;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin>> a[i];
	for(int j=1;j<=m;j++) cin >> b[j];
	int g=0;
	for(int i=2;i<=n;++i) g=__gcd(g,abs(a[i]-a[1]));
	for(int i=1;i<=m;i++) cout << __gcd(a[1]+b[i],g) << " ";
    return 0;
}