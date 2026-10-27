#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hw31.INP","r+",stdin);
	freopen("hw31.OUT","w+",stdout);
	int n;cin >> n;
	int a[1000],m=0;
	for(int i=0;i<1000;i++)
	{
		if(n!=0)
		{
			a[i]=n%2;
			n/=2;
			m++;
		}	
		else break;
	}
	for(int i=m-1;i>=0;i--)
	{
		cout << a[i];
	}
	return 0;
}
