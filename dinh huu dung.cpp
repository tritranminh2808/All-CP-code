#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int b[N];
int mark[N];
signed main() {
    if (fopen("lmh_swapsort.inp", "r")) {
        freopen("lmh_swapsort.inp", "r", stdin);
        freopen("lmh_swapsort.out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b, b+n, a[i]) - b;
        mark[a[i]] = i;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            mark[a[i]] = mark[i];
            swap(a[i], a[mark[i]]);
            v.emplace_back(mark[i], i);
        }
    }
    cout << v.size() << '\n';
    for (auto &p : v) cout << p.first << ' ' << p.second << '\n';
    return 0;
}