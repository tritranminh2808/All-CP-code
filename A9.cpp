#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,d,k=0;
	cin >> n >> d;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	double b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=d*1.0/a[i]+i*1.0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (b[i]>b[j]) k++;
		}
	}
	cout << k;
	return 0;
}
