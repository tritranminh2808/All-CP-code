#include <bits/stdc++.h>
using namespace std;
// int sol=1;
int n;
int cal(vector <int> a, int d){
    vector <int> dp(5005);
    int sol=1;
    unordered_map<int, int > mp;
    for(int i=1;i<=n;i++) {
        dp[i]=1;
        dp[i]+=mp[a[i]-d];
        mp[a[i]]=max(mp[a[i]],dp[i]);
        sol=max(sol,dp[i]);
    }
    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector <int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans=1;
    for(int i=-100;i<=100;i++) ans=max(ans,cal(a,i));
    cout << ans;
    return 0;
}
