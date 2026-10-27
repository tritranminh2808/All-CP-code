#include <bits/stdc++.h>
using namespace std;

long long b, n,l,r;
int main()
{
	
	cin >> n>>l>>r; long long a[n];for(long long i=0;i<n;i++) {
		
		cin >> a[i];
		if(a[i]>=l&&a[i]<=r)b++;
	}
	cout << b;

	return 0;
}
