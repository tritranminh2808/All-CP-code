#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++){
    	cin >> arr[i];
    	if(mp[arr[i]]==0) mp[arr[i]]=i+1;
	}
    vector<int> dp;
    for (int x : arr) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
	}
    cout << dp.size() << "\n";
    for(auto i : dp) cout << mp[i] << " ";
    return 0;
}

