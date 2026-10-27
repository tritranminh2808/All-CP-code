#include <bits/stdc++.h>
using namespace std;
char a[20][20];
int main(){
	int n,m,k; cin >> n >> m >> k;
	vector <string> str;
	str.push_back("");
	for(int i=1;i<=n;i++){
		string s; cin >> s;
		str.push_back(s);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;j++) a[i][j]=str[i][j-1];
	}
	for(int i=1;i<=n;i++){
		vector <char> v;
		for(int j=1;j<=m;j++){
			for(int l=1;l<=k;++l) v.push_back(a[i][j]);
		}
		for(int l=1;l<=k;l++) {
			for(auto i : v) cout << i;
			cout << "\n";
		}
	}
}
