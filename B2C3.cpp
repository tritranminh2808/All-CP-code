#include <bits/stdc++.h>

using namespace std;
int  main()
{
	freopen("B2C3.INP","r+",stdin);
	freopen("B2C3.OUT","w+",stdout);
	int n;cin>>n;long double a[n],tong=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		tong+=a[i];
	}
	cout << fixed << setprecision(2) << tong;
	return 0;
}
