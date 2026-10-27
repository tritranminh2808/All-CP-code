#include <bits/stdc++.h>
using namespace std;

long long b, n;
int main()
{
	
	cin >> n; long long a[n];for(long long i=0;i<n;i++) cin >> a[i];
	
	long long min=a[0],  vtsnn=1;
	for(long long i=1;i<n;i++)
	{
		
		if (min > a[i])
		{
			vtsnn=i+1;
			min=a[i];
		} 
	}
	cout <<  vtsnn;

	return 0;
}
