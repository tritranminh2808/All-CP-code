#include <bits/stdc++.h>
using namespace std;
signed main(){
	string s; cin >> s;
	for(int i=0;i<s.length();i+=2){
		int ii=int(s[i])+(s[i+1]-'0');
		if(ii>90) ii=65+ii-91;
		cout << char(ii);
	}
	return 0;
}
