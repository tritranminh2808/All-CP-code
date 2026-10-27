#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b){
	return a/__gcd(a,b)*b;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b;
        cin >> a >> b;
        long long l = lcm(a,b);
        long long du = (a+b)%l;
        cout << l-du << "\n";
    }
    return 0;
}
