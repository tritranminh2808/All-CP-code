#include <bits/stdc++.h>
using namespace std;
#define int long long
bool dau[100005];
int g[100005];
int snt[13]={2,3,5,7,11,13,17,19,23,29,31,37,41};
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int mask=1;mask<(1<<13);mask++){
        int x=1;
        for(int i=0;i<13;i++) if((mask>>i)&1) x*=snt[i];
        g[mask]=x;
        if(__builtin_popcount(mask)%2==1) dau[mask]=1;
    }
    while(t--){
        int x; cin >> x;
        int l=1,r=304250263527210;
        while(l<r){
            int mid=(l+r)/2;
            int cnt=0;
            for(int i=1;i<(1<<13);i++) {
                if(dau[i]) cnt+=mid/g[i];
                else cnt-=mid/g[i];
            }
            if(cnt>=x) r=mid;
            else l=mid+1; 
        }
        cout << l << "\n";
    }
    return 0;
}