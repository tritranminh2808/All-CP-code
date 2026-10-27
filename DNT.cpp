#include<bits/stdc++.h>
using namespace std;

bool check[(int)5e7 + 5];

int main()
{
	freopen("007DNT.INP","r",stdin);
	freopen("007DNT.OUT","w+",stdout);
	int n,t=0;
	cin >> n;
	for(int i=0;i<n+5;i++)
	{
		check[i]=0;
	}
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
	for(int i=2;i<=n;i++)
	{
		t += (check[i] == 0);
	}
	cout << t;
	return 0;
}
