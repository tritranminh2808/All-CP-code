#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
	freopen("lcmseq.inp","r",stdin);
	freopen("lcmseq.out","w",stdout);
    int n;
    cin >> n;
	int res=lcm(n/2,n-n/2);
    cout << res;
}

