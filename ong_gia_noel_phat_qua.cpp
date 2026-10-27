#include <bits/stdc++.h>
using namespace std;
using ldb=long double;
using ll=long long;
ldb dp[2][200005];
pair <ll,ll> a[200005];
int n,sx,sy;
ldb cal(ll a, ll b , ll c , ll d){
    return sqrtl((c-a)*(c-a)+(d-b)*(d-b));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> sx >> sy;
    a[0].first=sx;
    a[0].second=sy;
    for(int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
    for(int i=1;i<=n;i++){
        dp[0][i]=min(dp[0][i-1],dp[1][i-1])+cal(a[i].first,a[i].second,a[i-1].first,a[i-1].second);
        dp[1][i]=min(dp[0][i-1],dp[1][i-1])+cal(a[i-1].first,a[i-1].second,sx,sy)+ cal(sx,sy,a[i].first,a[i].second);
    }
    cout << fixed << setprecision(15) << min(dp[0][n],dp[1][n]);
    return 0;
}