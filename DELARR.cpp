#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	vector<long long> a(n);
	for (long long i = 0;i<n;++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long pf = 0;
	unordered_map<long long, long long> mp;
	mp[0] = -1;
	long long res = 0;
	for (long long i = 0;i<n;++i){
		pf+=a[i];
		if(mp.find(pf)!=mp.end()){
			res = max(res, i-mp[pf]);
		}else mp[pf] = i;
	}
	cout << n-res;
}
