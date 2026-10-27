#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("B12.INP","r+",stdin);
	freopen("B12.OUT","w+",stdout);
	int n;cin>>n;int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int tong=0,cs=0;float tbc;
	for(int i=1;i<n;i+=2)
	{
		if(a[i]%2==1)
		{ 
			tong+=a[i];
			cs++;
		}
	}
	if(cs==0)
	{
		cout<< "khong ton tai";
		return 0;
	}
	tbc=(float)tong/cs;
	cout << fixed <<setprecision(2) << tbc;
	return 0;
}
