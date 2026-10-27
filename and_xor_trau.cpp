#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int q; cin >> q;
    while(q--){
        int cc;
        cin >> cc;
        if(cc==1){
            int l,r; cin >> l>> r;
            int sol=0;
            for(int i=l;i<=r;i++) sol+=a[i];
            for(int i=1;i<=n;i++) cout << a[i] << " ";
            cout << sol << "\n";
        }
        else if(cc==2){
            int l,r,x; cin >> l >> r >> x;
            for(int i=l;i<=r;i++) a[i]&=x;
        }
        else{
            int l,r,x; cin >> l >> r >> x;
            for(int i=l;i<=r;i++) a[i]^=x;
        }
    }
}

