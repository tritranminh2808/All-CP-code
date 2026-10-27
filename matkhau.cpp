#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
	while(q--){
//		for(int i=0;i<30;i++) a[i]=0;
		string s; cin >> s;
		int n=s.length();
		unordered_map<char,int> mp;
		for(int i=0;i<n;i++) mp[s[i]]++;
		for(auto i : mp) {
			if(i.second==1) {
				cout << i.first;
				break;
			}
		}
	}
	
	return 0;
}
