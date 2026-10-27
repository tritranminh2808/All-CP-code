#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("substr.inp","r",stdin);
	freopen("substr.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		string s; int k;
		cin >> s;cin >> k;
		vector <int> dem(270,0);
		int l=0,r=1,sol=r-l+1;
		dem[s[l]-'A']++;
		while(r<s.length()&&l<r){
			dem[s[r]-'A']++;
			while(l<r&&dem[s[r]-'A']>k){
				dem[s[l]-'A']--;
				l++;
			}
			sol=max(sol,r-l+1);
			r++;
		}
		cout << sol << "\n";
	}
}
