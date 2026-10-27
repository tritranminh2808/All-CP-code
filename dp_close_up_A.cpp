#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[2005][2005];
const int mod=1e9+7;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,h; cin >> n >> h;
    vector <int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
            if(a[i]+j==h) dp[i][j]=(dp[i][j]+dp[i-1][j-1]+dp[i-1][j])%mod;
            if(a[i]+j+1==h) dp[i][j]=(dp[i][j]+dp[i-1][j]*(j+1)+dp[i-1][j+1]*(j+1))%mod;
        }
    }
    cout << dp[n][0]%mod;
}