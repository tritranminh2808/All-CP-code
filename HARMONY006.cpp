#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("HARMONY006.INP","r+",stdin);
	freopen("HARMONY006.OUT","w+",stdout);
	int n,k;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		k=0;
		int m;
		cin >> m;
		int b[m];
		for(int j=0;j<m;j++)
		{
			cin >> b[j];
		}
		for( int j=0;j<m-1;j++ )
		{
			if (abs(b[j+1]-b[j])==1) k ++ ;
		}
		if (k>m/2)  cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}
	return 0;
}
