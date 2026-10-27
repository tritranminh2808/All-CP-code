#include <bits/stdc++.h>
using namespace std;
long long dp[505][505];
bool a[505][505];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    long long mod;
    cin >> m >> n >> mod;
    for(int i=1;i<=n;i++){
        string s; cin>> s;
        for(int j=0;j<m;j++) a[i][j+1]=s[j]-'0';
    }
    int x=0,y=0;
    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=1;j<=n;j++) if(a[j][i]) cnt++;
        if(cnt==0) x++;
        else if(cnt==1) y++;
    }
    dp[x][y]=1;
    for(int cc=1;cc<=m-n;cc++){
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m-i;j++){
                if(!dp[i][j]) continue;
                if(i>=2) dp[i-2][j+2]=(dp[i-2][j+2]+dp[i][j]*((i-1)*i/2)%mod)%mod;
                if(j>=2) dp[i][j-2]=(dp[i][j-2]+dp[i][j]*((j-1)*j/2)%mod)%mod;
                if(i>=1&&j>=1) dp[i-1][j]=(dp[i-1][j]+dp[i][j]*i%mod*j%mod)%mod;
            }
        }
    }
    cout << dp[0][0]%mod;
}