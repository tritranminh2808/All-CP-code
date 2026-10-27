#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
        int a,b,x,y; cin >> a >> b >> x >> y;
        if(a==b){
            cout << "0\n";
            continue;
        }
        int sol=0;
        if(a<b){
            if(x<=y) sol=(b-a)*x;
            else {
                int k=b,l=a;
                if(b%2==1) b--;
                if(a%2==1) a++;
                int chan=(b-a)/2;
                if(k%2==1) chan++;
                // cout << chan;
                sol+=chan*y;
                sol+=(k-l-chan)*x;
            }
            cout << sol << "\n";
        }
        else{
            if(a%2==0||a-b>1) cout << -1 << "\n";
            else cout << y << "\n";
        }

    }
    return 0;
}