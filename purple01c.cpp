#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
// int f[5005][5005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    if(n>27){
        vector <int> sech;
        for(int i=0;i<n;i++) {
            cin >> a[i];
            if(a[i]) sech.push_back(i);
        }
        int ans=INT_MAX;
        for(long long mask=1;mask<(1<<n);mask++){
            if(__builtin_popcount(mask)!=k) continue;
            bool stop=0;
            for(int i=0;i<n;i++) {
                if(a[i]&&(mask>>i)&1) {
                    stop=1;
                    break;
                }
            }
            int dem=0;
            // vector <bool> moved(n+1);
            if(stop) continue;
            vector <int> pp;
            for(int i=0;i<n;i++) if((mask>>i)&1) pp.push_back(i);
            for(int i=0;i<k;i++) dem+=abs(pp[i]-sech[i]);
            ans=min(ans,dem);
        }
        cout << ans;
        return 0;
    }
    if(k==0) {
        cout << 0;
        return 0;
    }
    vector <int> x,y;
    for(int i=0;i<n;i++){
        if(a[i]) x.push_back(i);
        else y.push_back(i);
    }
    int ans=1e16;
    
    cout << ans << "\n";
}
