#include<bits/stdc++.h>
using namespace std;

bool check[(int)5e7 + 5];

int main()
{
	freopen("KTDNT.INP","r",stdin);
	freopen("KTDNT.OUT","w+",stdout);
	int n,m,t=0;
	cin >> m >> n;
	for(int i=2;i*i<=n;i++)
	{
		if(check[i]!=0) continue;
		else
		{
			for(int k=i;i*k<=n;k++)
			{
				check[i*k]=1;
			}
		}		
	}
	for(int i=m;i<=n;i++)
	{
		t += (check[i] == 0);
	}
	cout << t;
	return 0;
}
