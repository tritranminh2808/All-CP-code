#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("NEW.inp","r",stdin);
	freopen("NEW.out","w",stdout);
	int n,a,b; cin >> n >>a >> b;
	long long ga=a/n,gb=b/n,ra=a%n,rb=b%n;
	if(ra+rb+1-n>0) cout << (long long) ga*gb*n+(ra+1)*gb+(rb+1)*ga+(ra+rb+1-n);
	else cout << (long long) ga*gb*n+(ra+1)*gb+(rb+1)*ga;
	return 0;
}
