#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#pragma GCC target("sse4")
using namespace std;

const int N = 1000000;

vector<int> f[N + 1];

void s(int lim) {
    for (int i = 2; i <= lim; ++i) {
        if (f[i].empty()) {
            for (int j = i; j <= lim; j += i) {
                f[j].push_back(i);
            }
        }
    }
}

int sol(int l, int r) {
    s(r);
    map<vector<int>, int> p;
    for (int i = l; i <= r; ++i) {
        vector<int> ps = f[i];
        sort(ps.begin(), ps.end());
        p[ps]++;
    }

    int res = 0;
    for (auto &e : p) {
        int c = e.second;
        if (c > 1) {
            res += c * (c - 1) / 2;
        }
    }

    return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int l, r;
    cin >> l >> r;

    int res = sol(l, r);
    cout << res << endl;

    return 0;
}

