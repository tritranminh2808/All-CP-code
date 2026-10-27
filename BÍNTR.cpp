#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long res = 0;
	long long i = 1;
	while (i<=n){
		long long a = n/i;
		long long j = n/a + 1;
		res += a*(j-i);
		i = j;
	}
	cout << res;
	return 0;
}

