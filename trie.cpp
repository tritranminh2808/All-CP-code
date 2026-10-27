#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    // memset(st,-1,sizeof(st));
    cin >> q;
    map<string, int> mp;
    while(q--){
        int o;
        cin >> o;
        // cout << o << "\n";
        string s; cin >> s;
        if(o==1) mp[s]++;
        else if(o==2) mp[s]--;
        else{
            if(mp[s]>0) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}