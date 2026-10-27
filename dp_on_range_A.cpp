#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>> n;
    string s; cin >> s;
    s='!'+s+'!';
    string t=s;
    reverse(t.begin(),t.end());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << n-dp[n][n];
    return 0;
}