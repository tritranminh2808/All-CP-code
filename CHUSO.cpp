#include <bits/stdc++.h>
using namespace std;
string s="123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899";
int cs=0;
int main()
{
	freopen("CHUSO.INP","r+",stdin);
	freopen("CHUSO.OUT","w+",stdout);
	int n,k;cin>>n>>k;for(int i=1;i<=n;i++){
		cout << i;
	}cout << '\n';if(n>9) {
		cs+=9;
		cs+=(n-10)*2+2; 
	}
	else cs+=n;
	if(k>cs) cout << -1;
	else cout << s[k-1];
	return 0;
}
