#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>> a[i];
    int gg=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            cout << 1; return 0;
        }
        gg=__gcd(gg,a[i]);
    }
    if(gg>1){
        cout << -1;
        return 0;
    }
    unordered_map<int,int> f;
    for(int i=1;i<=n;i++){
        // cur=f;
        vector <pair <int, int > > cur;
        for(auto j:f) cur.push_back({__gcd(j.first,a[i]),j.second+1});
        cur.push_back({a[i],1}); 
        for(auto j:cur) if(f.find(j.first)==f.end()||f[j.first]>j.second) f[j.first]=j.second;
        
    }
    cout << f[1];
    return 0;
}