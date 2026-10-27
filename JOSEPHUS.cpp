#include <bits/stdc++.h>
using namespace std;

int sol1(int n, int m, int l) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = (res + m) % i;
    }
    
    res = (res + l) % n;
    return res;
}

int sol2(int n, int m, int r) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = (res + m) % i;
    }
    res = (r - res + n) % n;
    return res;
}

int main() {
    int n, m, p, y;
    cin >> n >> m >> p >> y;

    int q = sol1(n, m, p);

    int x = sol2(n, m, y);

    cout << q << " " << x;
    return 0;
}

