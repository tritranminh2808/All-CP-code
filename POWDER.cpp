#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, a, xa, b, yb;
    cin >> n >> a >> xa >> b >> yb;
    long long minCost = LLONG_MAX;
    for (long long x = 0; x <= (n + a - 1) / a; ++x) {
        long long remaining = n - x * a;
        if (remaining <= 0) {
            minCost = min(minCost, x * xa);
            break;
        }
        long long y = (remaining + b - 1) / b;
        minCost = min(minCost, x * xa + y * yb);
    }
    
    cout << minCost;
    return 0;
}
