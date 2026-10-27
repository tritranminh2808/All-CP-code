#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000005];
int mod=1e9+7;
signed main(){
    dp[1]=1;
    dp[2]=2;
    dp[3]=2;
    for(int i=4;i<1000005;++i){
       dp[i] =(dp[i-2]%mod+dp[i-3]%mod)%mod;
    }
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        cout << dp [n] << "\n";
    }
}

