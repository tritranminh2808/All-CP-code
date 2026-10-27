#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("CHIAHETN.INP","r+",stdin);
	freopen("CHIAHETN.OUT","w+",stdout);
	int a,b,n;
	cin >> a >> b >> n;
	while (a%n!=0)
	{
		a++;
	}
	while (b%n!=0)
	{
		b--;
	}
	int ssh;
	ssh=(b-a)/n+1;
	cout << ssh;
	return 0;
}
