#include <bits/stdc++.h>
using namespace std;
const int MOD = 123456789;
int dp[5000+1][5000+1];
int main() {
    int n;
    cin >> n;
    
    dp[0][0]=1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i<=j) {
                dp[i][j] += (dp[i-1][j] + dp[i-1][j-i]) % MOD;
            }else{
            	dp[i][j] = dp[i-1][j]%MOD;
			}
        }
    }
    cout << dp[n][n] % MOD;
    return 0;
}
