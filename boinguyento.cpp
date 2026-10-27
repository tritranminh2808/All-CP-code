#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n; 
    int k; 
    cin >> n >> k;
    vector<int> a(k);
    for(int i=0;i<k;i++) cin >> a[i];
    int ans = 0;
    for(int mask=1;mask<(1<<k);mask++){
        int lcm=1,bit=0;
        bool sech=1;
        for(int i=0;i<k;i++){
            if(mask&(1<<i)){
                if(lcm>n/a[i]) { 
                    sech=0; 
                    break; 
                }
                lcm*=a[i]; 
                bit++;
            }
        }
        if(!sech) continue;
        if(bit&1) ans+=n/lcm;
        else ans-=n/lcm;
    }
    cout << ans;
    return 0;
}

