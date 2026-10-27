#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("RAB.INP","r+",stdin);
	freopen("RAB.OUT","w+",stdout);
	long long a,b,x,y;cin >> x >> y >> a >> b;
	long long kc=y-x ,t=a+b;
	if(kc%t!=0) 
	{
		cout << "-1";
		return 0;	
	}
	long long h=kc/t;cout << h;
	return 0;
}
