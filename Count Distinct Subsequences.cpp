#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000005];
const int mod=1e9+7;
int last[1000005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    memset(last,-1,sizeof(last));
    int n=s.length();
    s='!'+s;
    dp[0]=1;
    // last[s[0]]=0;
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1]*2%mod;
        if(last[s[i]]!=-1) dp[i]=(dp[i]-dp[last[s[i]]]+mod)%mod;
        last[s[i]]=i-1;
    }
    cout << (dp[n]-1+mod)%mod;
}