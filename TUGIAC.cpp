#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("TUGIAC.INP","r+",stdin);
	freopen("TUGIAC.OUT","w+",stdout);
	int a,b,c,d;
	while (cin >> a >> b >> c >> d){
		if(a+b+d<c||a+b+c<d||b+c+d<a||b+c+a<d||c+d+b<a||c+d+a<b||a+c+d<b||a+c+b<d||b+d+c<a||b+d+a<c||a+d+c<b||a+d+b<c){
			cout << "NO" << "\n";
		}
		else cout << "YES\n";
	}
	return 0;
}
