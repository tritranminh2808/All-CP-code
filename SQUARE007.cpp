#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("SQUARE007.INP","r+",stdin);
	freopen("SQUARE007.OUT","w+",stdout);
	int n;
	cin >> n;
	int i=1,bien=2,x;
	while (i<=n)
	{
		int kc=bien-1;
		int dmc=kc*2+1;
		x=dmc*dmc;
		i++;
		bien=dmc;
	}
	cout << x;
	return 0;
}
