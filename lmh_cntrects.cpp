#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k;
pair <int ,int> a[25];
const int mod=1e9+7;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<k;i++) cin >> a[i].first >> a[i].second;
    int ans=0;
    for(int mask=1;mask<(1<<k);mask++){
        int ax=n,ay=m,bx=0,by=0;
        // cout << mask << "\n";
        for(int i=0;i<k;i++) {
            if((mask>>i)&1){
                ax=min(ax,a[i].first);
                ay=min(ay,a[i].second);
                bx=max(bx,a[i].first);
                by=max(by,a[i].second);
            }
        }
        // cout << ax << " " << ay << " " << bx << " " << by << "\n";
        int cnt=0;
        cnt+=((((ax)%mod*(ay)%mod)%mod*(n-bx+1)%mod)%mod*(m-by+1)%mod)%mod;
        if(__builtin_popcount(mask)%2==1) ans=(ans+cnt)%mod;
        else ans=(ans-cnt+mod)%mod;
    }
    cout << ans%mod;
    return 0;
}