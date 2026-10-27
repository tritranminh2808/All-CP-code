#include <bits/stdc++.h>
using namespace std;
long long ss(int n)
{
	long long tong=n;
	while (n!=0)
	{
		tong+=n%10;
		n/=10;
	}
	return tong;
}
int main ()
{
	freopen("SINHSO.INP","r+",stdin);
	freopen("SINHSO.OUT","w+",stdout);
	int n;cin >> n;
	for(int i=1;i<n;i++)
	{
		if(ss(i)==n)
		{
			cout << i;
			break;
		}
	}
	return 0;
}
