#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("BAI315.INP","r+",stdin);
	freopen("BAI315.OUT","w+",stdout);
	int n;
	cin >> n;
	int i=1,dem=0;
	while(pow(2,i)<=n)
	{
		if(pow(2,i)-1<=n) dem++;
		i++;
	}
	cout << dem;
	return 0;
}
