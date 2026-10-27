#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n,qx,qy,px,py; cin >> n>> px >> py >> qx >> qy;
        
        vector <int> a;
        int S=0,maxx=0;
        for(int i=1;i<=n;i++){
            int u;cin >> u;a.push_back(u);
            S+=u;
            maxx=max(maxx,u);
        }
        int c1=qx-px,c2=qy-py;
        int kc=c1*c1+c2*c2;
        if(S*S<kc) {
            cout << "NO\n";
            continue;
        }
        
        else {
            int cc=max((int)0,2*maxx-S);
            if(cc*cc<=kc) cout << "YES\n";
            else cout << "NO\n";
        }

    }
    return 0;
}