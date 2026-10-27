#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("TRAP.INP","r",stdin);
	freopen("TRAP.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;cin >> n;
	int a[n][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++)
			cin >> a[i][j];
	}
	int min1=a[0][0],max1=a[0][0],min2=a[0][1],max2=a[0][1];
	for(int i=1;i<n;i++)
	{
	
		min1=min(min1,a[i][0]);
		max1=max(max1,a[i][0]);
	}

	for(int i=1;i<n;i++)
	{
		
		min2=min(min2,a[i][1]);
		max2=max(max2,a[i][1]);
	}
	cout << min1 << " " << max2 << " " << max1 << " " << min2;
	return 0;
}
