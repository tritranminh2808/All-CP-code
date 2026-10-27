#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen ("DTHUONG.INP","r+",stdin);
	freopen ("DTHUONG.OUT","w+",stdout);
	int n,max=0;cin >> n;int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		if (max<=a[i]){
			max=a[i];
			cout << max << " ";
			
		}
		else cout << max << " ";
	}
	return 0;
}
