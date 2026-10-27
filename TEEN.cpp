#include <bits/stdc++.h>
using namespace std;
int t,e,n;
int main()
{
	freopen("TEEN.INP","r+",stdin);
	freopen("TEEN.OUT","w+",stdout);
	string a;getline(cin,a);
	for(int i=0;i<a.length();i++){
		if(int(a[i])==84) t++;
		else if(int(a[i])==69) e++;
		else if(int(a[i])==78) n++;
	}
	cout << t << "\n" << e << "\n" << n << '\n';
	e/=2;
	
	cout << min(min(t, e), n);
	return 0;
}
