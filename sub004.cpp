#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

void q() {
	
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int m = a[0], s = a[0], r = a[0];
    for (int i = 1; i < n; i++) {
        s = max(a[i], s + a[i]);
        m = max(m, s);
        if (a[i] > 0) r += a[i];
        else r = max(r, a[i]);
    }

    cout << r << ' ' << m << '\n';
}

signed main() {
	freopen("sub004.inp","r",stdin);
	freopen("sub004.out","w",stdout);
    int t;
    cin >> t;
    while (t--) q();
}

