#include <bits/stdc++.h>
using namespace std;
const long long p=1e5+5;
long long n,m;
long long a[p];
int main()
{
	cin >> n >> m;
	for(long long i=0;i<n;i++) cin >> a[i];
	sort (a,a+n);
	for(long long i=0;i<m;i++){
		long long l,r; cin >> l >> r;
		long long *x=lower_bound(a,a+n,l);
		long long *y=lower_bound(a,a+n,r);
		if(binary_search(a,a+n,r)){
			cout <<  ( y-a)-(x-a)+1 <<endl;
		}
		else cout <<  (y-a-1)-(x-a)+1 << endl;
		
	}
	return 0;
}
