#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("DOIXUNG.INP","r+",stdin);
	freopen("DOIXUNG.OUT","w+",stdout);
	int n;cin >> n;int a[n];for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if( n%2==0)
	{
		int c=n/2-1,b=n/2;
		while(c>=0&&b<n)
		{
			if(a[c]!=a[b])
			{
				cout << "0";
				return 0;
			 } 
			c--;b++;
		}
		cout << "1";
		return 0;
	}
	else{
		int b=n/2-1,c=n/2+1;
		while(b>=0&&c<n)
		{
			if(a[c]!=a[b])
			{
				cout << "0";
				return 0;
			 } 
			c++;b--;
		}
		cout << "1";
		return 0;
	}
	return 0;
}



