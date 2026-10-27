#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("THUNHI.INP","r+",stdin);
	freopen("THUNHI.OUT","w+",stdout);
	int n;cin >> n;int a[n];for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);int max=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]!=max) 
		{
			cout << a[i];return 0;
		}
	}
	return 0;
}
