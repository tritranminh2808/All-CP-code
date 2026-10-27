#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("TONG.INP","r+",stdin);
	freopen("TONG.OUT","w+",stdout);
	int n;cin >> n;int tong=0;
	for(int i=1;i<=n;i++)
	{
		tong +=i;
	}
	cout << tong;
	return 0;
}
