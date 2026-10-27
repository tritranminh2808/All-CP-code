#include <bits/stdc++.h>
using namespace std;
int  main()
{
	freopen("ARRAYSUM.INP","r+",stdin);
	freopen("ARRAYSUM.OUT","w+",stdout);
	int n;
	cin >> n;
	float k=1,k2,z;;
	float tong=0;
	while (k<=n)
	{
		
		k2=k*k;
		z=1/k2;
		tong +=z;
		k++;
	}cout << fixed << setprecision(2) << tong;
	return 0;
}
