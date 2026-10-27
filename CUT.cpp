#include <bits/stdc++.h>
using namespace std;
unsigned long long a,cstc=0;
int main()
{
	long long n,m,k; cin >> n >> m >>k; if(n*m<=k){
		cout << n*m;return 0;
	}
	if(n>m) swap(n,m);
	long long z=k/2;
	
	if(z>n-1) z=n-1;
	long long t=k-z;
	if(t>m-1) t=m-1;
	cout << (long long ) (z+1)*(t+1);
	return 0;
}
