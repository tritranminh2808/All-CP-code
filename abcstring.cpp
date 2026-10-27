#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    string s;
    cin >> s;
    int n = s.size();
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = 1;
    int a = 0, b = 0, c = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a++;
        else if (s[i] == 'B') b++;
        else c++;
        pair<int, int> p = {a - b, a - c};
        res += mp[p];
        mp[p]++;
    }
    cout << res;
}

