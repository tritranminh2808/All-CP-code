#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	string a, b; cin >> a >> b;
	unordered_map<char,int> mp;
	for(int i=1;i<a.length();i++) mp[a[i]]++;
	int cnt=a.length()*b.length();
	for(int i=0;i<b.length()-1;i++) cnt-=mp[b[i]];
	cout << cnt;
}
