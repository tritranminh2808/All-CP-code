#include <bits/stdc++.h>
using namespace std;
multiset <char, greater<char> > a;
bool cmp(char a, char b){
	return a>b;
}
int d=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string n; cin >> n; 
	bool check=0;
	for(auto i : n) {
		if(i=='0') check=1;
		a.insert(i);
		d+=i-'0';
	}
	if(d%3!=0||check==0){
		cout << "-1";return 0;
	}
	for(auto i : a) cout << i;
	return 0;
}
