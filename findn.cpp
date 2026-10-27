#include <bits/stdc++.h>
using namespace std;

vector<long long> s;

void g(long long x, int d) {
    if (d == 0) {
        s.push_back(x);
        return;
    }
    g(x * 10 + 4, d - 1);
    g(x * 10 + 7, d - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

  //  freopen("findn.inp", "r", stdin);
   // freopen("findn.out", "w", stdout);

    for (int i = 1; i <= 10; i++) g(0, i);
    sort(s.begin(), s.end());

    int t, k;
    cin >> t;
    while (t--) {
        cin >> k;
        cout << s[k - 1] << "\n";
    }
    return 0;
}

