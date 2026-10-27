#include <bits/stdc++.h>
using namespace std;
const long long  p=1e6+5;
long long  a[p];
long long  n,sol=0;
int  main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(long long  i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	long long  avg=a[n/2];
	for(long long  i=0;i<n;i++) sol+=abs(a[i]-avg);
	cout << sol;
	return 0;
	
}
