#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main(){
	long long n,m;cin >> m >> n;
	cout << (long long) m+n-__gcd(m,n);
	return 0;
}
