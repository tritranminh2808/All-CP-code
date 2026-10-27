#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("CHIANHOM.INP","r+",stdin);
	freopen("CHIANHOM.OUT","w+",stdout);
	long long n,h,k,p,b=0;
	cin >> n >> h;
	long long a[n];
	for(long long i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n-1;i++)
	{
		long long j=i+1;
		while (a[j]-a[i]<=h)
		{
			j++;
		}
		
		b++;
		i=j-1;
	}
	cout << b;
	return 0;
}
