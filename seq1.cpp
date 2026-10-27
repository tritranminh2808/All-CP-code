#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10005], dp[10005];
signed main(){
    int n, k; cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        dp[i]=a[i];
        for (int j=max((int)0,i-k);j<i;j++) dp[i]=max(dp[i],dp[j]+a[i]);
    }
    int res=-1e18;
    for (int i=1;i<=n;i++) res=max(res,dp[i]);
    cout << res;
    return 0;
}

