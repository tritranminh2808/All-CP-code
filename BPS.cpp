#include <bits/stdc++.h>
using namespace std;
int uc(int a,int b)
{
	if (b==0) return a;
	else return uc(b,a%b);
}
int main()
{
	freopen("BPS.INP","r+",stdin);
	freopen("BPS.OUT","w+",stdout);
	int n,tu=0,mau=1;
	cin >> n;
	for(int i=n/2;i>1;i--)
	{
		int j=n-i;
		if(uc(i,j)==1) 
		{
				cout << i << "/"  << j;
				break;
		}
	}

	return 0;
}
