#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int d[300];
signed main(){
	cin >> s;
	int sol=1;
	
	for(int i=0;i<s.length();++i){
		sol+=i-d[s[i]]++;
	}
	cout << sol;
}
