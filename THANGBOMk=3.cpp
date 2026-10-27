#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (n == 1) {
        cout << v[0] << endl;
        return 0;
    }

    if (n == 2) {
        cout << v[0] + v[1] << endl;
        return 0;
    }

    vector<int> dp(n, 0);
    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max({v[0] + v[1], v[0] + v[2], v[1] + v[2]});

    for (int i = 3; i < n; ++i) {
        dp[i] = max({dp[i-1], dp[i-2] + v[i], dp[i-3] + v[i-1] + v[i]});
    }
	for(int i=0;i<n;i++) cout << dp[i] << " ";
    //cout << dp[n-1] << endl;
    return 0;
}

