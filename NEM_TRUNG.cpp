#include <bits/stdc++.h>

using namespace std;
int dp[1005][1005];
int main() {
    int T;
    cin >> T;
   

    for (int n = 1; n <= 1000; ++n) {
        for (int m = 1; m <= 1000; ++m) {
                if (n == 1) {
                    dp[n][m] = m;
                } else {
                    dp[n][m] = 1e7+5;
                    for (int x = 1; x <= m; ++x) {
                        int te = max(dp[n-1][x-1], dp[n][m-x]);
                        dp[n][m] = min(dp[n][m], te + 1);
                    }
                }
            }
        }
    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << dp[N][M] << endl;
    }
    return 0;
}

