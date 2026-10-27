#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("cmsn1.inp","r",stdin);
	vector <string> v;
	string m; while(cin >> m)  v.push_back(m);
	for(int i=0;i<v.size();i++){
		int tp=0;
		for(int j=0;j<v[i].length();j++){
			tp=tp*2+(int)v[i][j]-48;
		}
		cout << char(tp);
	}
	return 0;
}
