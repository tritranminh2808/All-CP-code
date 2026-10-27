#include <bits/stdc++.h>
using namespace std;
bool snt(int n)
{
	int x=0;
	if (n==0||n==1) return false;
	else if (n==2||n==3) return true;
	for(int i=2;i<sqrt(n);i++)
	{
		if (n%i==0)
		{
			x++;
			break;
		}
	}
	if (x!=0) return false;
	else if (x==0) return true;
}
int main ()
{
	freopen("SNT.INP","r+",stdin);
	freopen("SNT.OUT","w+",stdout);
	int n,x=0;
	cin >> n;
	while (n>0)
	{
		if (snt(n)== true)
		{
			n/=10;
		}
		else
		{
			x++;
			break;
		}
	}
	if (x==0) cout << "1";
	else cout << "0";
	return 0;
}
