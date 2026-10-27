#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll m = 1e9;

using mat = vector<vector<ll>>;

mat mul(const mat &a, const mat &b, int k) {
    mat c(k, vector<ll>(k));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
            for (int x = 0; x < k; ++x)
                c[i][j] = (c[i][j] + a[i][x] * b[x][j]) % m;
    return c;
}

mat pw(mat t, ll p, int k) {
    mat r(k, vector<ll>(k));
    for (int i = 0; i < k; ++i)
        r[i][i] = 1;
    while (p) {
        if (p % 2) r = mul(r, t, k);
        t = mul(t, t, k);
        p /= 2;
    }
    return r;
}

ll get(int k, const vector<ll> &b, const vector<ll> &c, ll n) {
    if (n <= k) return b[n - 1] % m;
    mat t(k, vector<ll>(k));
    for (int i = 0; i < k - 1; ++i)
        t[i][i + 1] = 1;
    for (int i = 0; i < k; ++i)
        t[k - 1][i] = c[k - i - 1];
    t = pw(t, n - k, k);
    ll r = 0;
    for (int i = 0; i < k; ++i)
        r = (r + t[k - 1][i] * b[i]) % m;
    return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<ll> b(k), c(k);
        for (int i = 0; i < k; ++i) cin >> b[i];
        for (int i = 0; i < k; ++i) cin >> c[i];
        ll n;
        cin >> n;
        cout << get(k, b, c, n) << '\n';
    }
    return 0;
}

