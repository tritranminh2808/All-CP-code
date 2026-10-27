#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000005][26];
const int mod=1e9+7;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<26;i++) dp[1][i]=1;
    if(s.length()==1) dp[1][s[0]-'A']=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<26;j++){
            // dp[i][j]=1;
            for(int k=0;k<26;k++) dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
            if(i>=s.length()&&j==s[s.length()-1]-'A') dp[i][j]=(dp[i][j]-dp[i-s.length()+1][s[0]-'A']+mod)%mod;
            
        }
    }
    int res=0;
    for(int i=0;i<26;i++){
        // cout << dp[n][i] << " ";
        res+=dp[n][i];
        res%=mod;
    }
    cout << res;
}