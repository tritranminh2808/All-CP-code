#include <bits/stdc++.h>
using namespace std;
int tcs(string s){
	int sol=0;
	for(int i=0;i<s.length();i++){
		sol+=int(s[i])-48;
	}
	return sol;
}
int main(){
	string s; cin >> s;
	cout << s.length() << "\n" << tcs(s);
	return 0;
}
