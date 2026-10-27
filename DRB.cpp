#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("DRB.INP","r+",stdin);
	freopen("DRB.OUT","w+",stdout);
	int a,b,c,d;cin >> a >> b >> c >> d;
	if(a<c&&b<d) 
	{
		cout << "-1";
		return 0;
	}
	if(a>c&&b>d) 
	{
		cout << "-1";
		return 0;
	}
	int n=abs(a-c),m=abs(b-d);
	cout << n/m;
	return 0;
}
