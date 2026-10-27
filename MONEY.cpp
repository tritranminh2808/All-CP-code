#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("MONEY.INP","r",stdin);
	freopen("MONEY.OUT","w",stdout);
	int g,s,k; cin >> g >> s >> k;int n;cin >> n;int a[n][3];for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin >> a[i][j];
		}
	}
	int l=g*17*29+s*29+k;
	for(int i=0;i<n;i++)
	{
		int r=a[i][0]*17*29+a[i][1]*29+a[i][2];
		l-=r;
	}
	if(l<0)
	{
		cout << "-1";
		return 0;
	}
	g=0;s=0;k=0;
	if(l>=493){
		g=l/493;
		l%=493;
	}
	if (l>=29){
		s=l/29;
		l%=29;
	}
	
	k=l;cout << g << " " << s << " " << k;
	return 0;
}
