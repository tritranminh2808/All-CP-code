#include <bits/stdc++.h>
using namespace std;
int main ()
{
	
	long long n,a,b; cin >> a >> b >> n;
	long long ga=a/n,gb=b/n,ra=a%n,rb=n-b%n-1;
	if(ra<rb) cout << (long long) (ga+1)*(gb+1)+ra*(ga+1)*gb+(rb-ra)*ga*gb+(n-1-rb)*(gb+1)*ga;
	else cout << (long long) (ga+1)*(gb+1)+rb*(ga+1)*gb+(ra-rb)*(ga+1)*(gb+1)+(n-1-ra)*(gb+1)*ga;
	return 0;
}
