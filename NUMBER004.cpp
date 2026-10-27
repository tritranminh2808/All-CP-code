#include <bits/stdc++.h>
using namespace std;
long long res=0;
int main()
{
	freopen("NUMBER004.inp","r",stdin);
	freopen("NUMBER004.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long n; cin >> n;
	long a[n];
	for(long i=0;i<n;i++)  {
		cin >> a[i];
		res+=a[i];
	}
	cout << res/2;	
	return 0;
}
