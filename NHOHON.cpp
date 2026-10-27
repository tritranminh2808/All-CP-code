#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("NHOHON.INP","r+",stdin);
	freopen ("NHOHON.OUT","w+",stdout);
	int n,m;
	cin >> n >> m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int j=0;j<m;j++)
	{
		cin >> b[j];
	}
	for(int i=0;i<m;i++)
	{
		int k=0;
		for(int j=0;j<n;j++)
		{
			if (b[i]>a[j]) k++;
		}
		cout << k << " ";
	}
	return 0;
}
