#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("MAXDIFF008.INP","r+",stdin);
	freopen("MAXDIFF008.OUT","w+",stdout);
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int k=0;
	for(int i=0;i<n-2;i++)
	{
		if(a[i+1]-a[i]>=k) k=a[i+1]-a[i];
		if (a[i+2]-a[i]>=k) k=a[i+2]-a[i];
	}
	cout << k;
	return 0;
}
