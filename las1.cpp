#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int sol=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,d; cin >> n>> d;
    vector <int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    unordered_map<int, int > mp;
    for(int i=1;i<=n;i++) {
        dp[i]=1;
        dp[i]+=mp[a[i]-d];
        mp[a[i]]=max(mp[a[i]],dp[i]);
    }
    for(int i=1;i<=n;i++) sol=max(sol,dp[i]);
    cout << sol;
    return 0;
}