#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("TICHLAYDU.INP","r+",stdin);
	freopen("TICHLAYDU.OUT","w+",stdout);
	int a,b,c;
	cin >> a >> b >> c;
	int t=a;
	for(int i=a+1;i<=b;i++)
	{
		t=t*i%c;
	}
	cout << t;
	return 0;
	}
