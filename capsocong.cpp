#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mx = 1, cur = 1;
    int d = a[1] - a[0];

    for (int i = 1; i < n; ++i) {
        if (i > 1 && a[i] - a[i - 1] == d) {
            ++cur;
        } else {
            d = a[i] - a[i - 1];
            cur = 2;
        }
        mx = max(mx, cur);
    }

    cout << mx;
    return 0;
}

