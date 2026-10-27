#include <bits/stdc++.h>
using namespace std;
int n, a[200001], r;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int j = upper_bound(a, a + n, a[i] + 5) - a;
        r = max(r, j - i);
    }
    cout << r;
}

