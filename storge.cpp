#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
long long dp[5005][5005],a[5005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i=0;i<n;++i) {
        cin >> a[i];
        b[i]=a[i];
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int m=b.size();
    // vector<vector<long long>> dp(n, vector<long long>(m));
    for (int j=0;j<m;++j) dp[0][j] = abs(a[0] - b[j]);

    for (int i=1;i<n;++i) {
        long long minn=1e18;
        for (int j=0;j<m;++j) {
            minn=min(minn, dp[i-1][j]);
            dp[i][j]=abs(a[i]-b[j])+minn;
        }
    }

    long long ans=1e18;
    for (int j=0;j<m;++j) ans = min(ans, dp[n - 1][j]);

    cout << ans;
    return 0;
}
