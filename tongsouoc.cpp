#include <bits/stdc++.h>
#define int ull
using ull=unsigned long long;
using namespace std;
signed main(){
//	freopen("tongsouoc.inp","r",stdin);
//	freopen("tongsouoc.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x,y; cin >> x >> y;
	int can=sqrt(y), can2=sqrt(x-1);
	int sum1=0,sum2=0;
	for (int i=1;i<=can;i++) sum1+=y/i;
	for (int i=1;i<=can2;i++) sum2+=(x-1)/i;
	sum1=2*sum1-can*can;
	sum2=2*sum2-can2*can2;
	cout << sum1-sum2;
//	cout << y-x+1+sum*(y-x+1);
	return 0;
}
