#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("ELEVATOR010.INP","r+",stdin);
//	freopen("ELEVATOR010.OUT","w+",stdout);
	int n,k,tong=0,count=1,x=1;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		count =1;
		x=1;
		while(count<=k&&i>=0)
		{
			tong+=abs(x-a[i]);
			x=a[i];
			count ++;
			if(count <=k )i--;
		}
		if(i<0) break;
		tong+=abs(1-a[i]);
	}
	cout << tong +a[0]-1;
	return 0;
}
