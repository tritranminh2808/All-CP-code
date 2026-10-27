#include <bits/stdc++.h>

using namespace std;
int  main()
{
	freopen("TS01.INP","r+",stdin);
	freopen("TS01.OUT","w+",stdout);
	int n;cin>>n;
	for(int i=1;i<n;i++)
	{
		int k=1;
		while (k<=i)
		{
			cout << i;
			k++;
		}
		cout << "\n";
	}
	return 0;
}
