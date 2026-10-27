#include <bits/stdc++.h>
using namespace std;
int dp[250][250],cur[250][250];
int a[250];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("248.in","r",stdin);
    freopen("248.out","w",stdout);
    int n; cin>> n;
    int sol=0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        sol=max(sol,a[i]);
        cur[i][i]=1;
    }
    for(int i=1;i<=n;i++) dp[i][i]=a[i];
    for(int len=2;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            for(int k=l;k<r;k++){
                if(cur[l][k]&&cur[k+1][r]&&dp[l][k]==dp[k+1][r]) {
                    dp[l][r]=max(dp[l][r],dp[l][k]+1);
                    cur[l][r]=1;
                }
                // else dp[l][r]=max({dp[l][r],dp[l][k],dp[k+1][r]});
            }
            sol=max(sol,dp[l][r]);
        }
    }
    cout << sol;
    return 0;
}