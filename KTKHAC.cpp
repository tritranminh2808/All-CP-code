#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("KTKHAC.INP","r+",stdin);
	freopen("KTKHAC.OUT","w+",stdout);
	int n; cin >> n; 
	for(int i=0;i<n;i++)
	{
		string a; cin >> a;
		bool check[150];int dem=0;
		for(int k=0;k<150;k++)
		{
			check [k]=0;
		}
		for(int j=0;j<a.length();j++)
		{
			if(check[int(a[j])]==0)
			{
				dem++;
				check[int(a[j])]=1;
			}
		}
		cout << dem << "\n";
	}
	
	return 0;
}
