#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= k; i++) {
        dp[i] = dp[i-1] + a[i];
    }

    for (int i = k + 1; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i-k] + a[i]);
    }

    cout << dp[n] << endl;

    return 0;
}

