#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
// int sol=1;
int n;
int dp[5005][5005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    // return t;
    while(t--){
        cin >> n;
        memset(dp,0,sizeof(dp));
        vector <int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        // set<int> st;
        sort(a.begin()+1,a.end());
        int ans=2;
        for(int i=1;i<n;i++) dp[i][n]=2;
        for(int i=n-1;i>=1;i--){
            int l=i-1,r=i+1;
            while(l>=1&&r<=n){
                if(a[l]+a[r]<a[i]*2) r++;
                else if(a[l]+a[r]>a[i]*2){
                    dp[l][i]=2;
                    l--;
                }
                else{
                    dp[l][i]=dp[i][r]+1;
                    ans=max(ans,dp[l][i]);
                    l--;
                    r++;
                }
            }
            while(l>0) {
                dp[l][i]=2;
                l--;
            }
        } 
        cout << ans << "\n";
    }
    return 0;
}