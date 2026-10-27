#include <bits/stdc++.h>
using namespace std;
int v[100005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector <int> a(n),b(n),arr(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        cin >> b[i];
        v[b[i]]=i;
    }
    for(int i=0;i<n;i++) arr[i]=v[a[i]];
    // cin >> n;
    unordered_map<int,int> mp;
    vector<int> dp;
    for (int x:arr) {
        // cout << x;
        auto it=lower_bound(dp.begin(), dp.end(), x);
        if (it==dp.end()) dp.push_back(x);
        else *it=x;
	}
    cout << dp.size();
    return 0;
}

