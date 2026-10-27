#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("SUMK.INP","r",stdin);
	freopen("SUMK.OUT","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n; cin >> n; 
	
	long long i=1;
	long long k=floor(sqrt(2*n));
	if(k*(k+1)==2*n) {
		cout << k;
		return 0;
	}
	cout << -1;
	return 0;
}
