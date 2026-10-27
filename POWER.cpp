#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long m) {
    if (b == 0) return 1;

    long long half = power(a, b/2, m);
    if (b%2) return ((half*half)%m*a)%m;
    else return (half*half)%m;
}

int main() {
	
    long long k, m, x; 
	cin >> k >> m >> x;

    cout << power(k,m,x);
}
