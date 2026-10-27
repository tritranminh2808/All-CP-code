#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n,l,r,k; cin >> n >> l >> r >> k;
        if(n%2==1) cout << l << "\n";
        else if(n==2) cout << "-1\n";
        else{
            int cnt=0;
            int x=l;
            while(x!=0){
                cnt++;
                x/=2;
            }
            int p=(1LL<<cnt);
            if(p>r) cout << "-1\n";
            else {
                if(k>n-2) cout << p << "\n";
                else cout << l << "\n";
            }
        }

    }
    return 0;
}