#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")
using namespace std;

int mx(vector<int>& h, int k) {
    int n = h.size(), nuoc = 0;

    vector<int> prefix(n), suffix(n);
    prefix[0] = h[0];
    suffix[n - 1] = h[n - 1];
    
    for (int i = 1; i < n; ++i) {
        prefix[i] = max(prefix[i - 1], h[i]);
    }
    
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = max(suffix[i + 1], h[i]);
    }

    function<void(int, vector<int>)> tr = [&](int sl, vector<int> ch) {
        if (sl == 0) {
            int water = 0;
            for (int i = 1; i < n - 1; i++) {
                int l_max = prefix[i - 1];
                int r_max = suffix[i + 1];
                water += max(0, min(l_max, r_max) - ch[i]);
            }
            nuoc = max(nuoc, water);
            return;
        }
        for (int i = 0; i < n; i++) {
            ch[i]++;
            prefix[0] = ch[0];
            for (int j = 1; j < n; ++j) {
                prefix[j] = max(prefix[j - 1], ch[j]);
            }
            
            suffix[n - 1] = ch[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                suffix[j] = max(suffix[j + 1], ch[j]);
            }

            tr(sl - 1, ch);
            ch[i]--;
        }
    };

    tr(k, h);
    return nuoc;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    cout << mx(h, k) << endl;
    return 0;
}

