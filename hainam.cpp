#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mx = 0, cur = 0, start = -1, end = -1, temp_start = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            if (cur == 0) temp_start = i;
            ++cur;
            if (cur > mx) {
                mx = cur;
                start = temp_start;
                end = i;
            }
        } else {
            cur = 0;
        }
    }

    cout << start+1 << " " << end+1;
    return 0;
}
