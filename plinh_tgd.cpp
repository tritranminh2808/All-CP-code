#include<bits/stdc++.h>
using namespace std;
#define int long long
int cal(int x){
    return (x-2)*(x-1)*x/6;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int dem=1;
    int ans=0;
    for(int i=1; i<n ;i++) {
        if(a[i]==a[i-1]) dem++;
        else{
            ans+=cal(dem);
            dem=1;
        }
    }
    ans+=cal(dem);
    cout << ans;
}