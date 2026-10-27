#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("KTTCS.INP","r+",stdin);
	freopen("KTTCS.OUT","w+",stdout);
	string a;cin >> a; long long t1=0,t2=0;
	for(int i=0;i<a.length();i++)
	{
		int k=int(a[i]) -48;
		if(i%2==0)
		{
			t1+=k;
		}
		if(k%2==1) t2+=k;
	}
	cout << t1 << "\n" << t2;
	return 0;
}
