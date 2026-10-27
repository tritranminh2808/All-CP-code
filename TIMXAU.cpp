#include <bits/stdc++.h>
using namespace std;

int  main(){
	freopen("TIMXAU.inp","r",stdin);
	freopen("TIMXAU.out","w",stdout);
	int k;cin >> k;
	string s;cin >> s;
	int i=1;
	vector <string> v;
	v.push_back(s);
	while(10){
		string a;
		for(int j=1;j<v[i-1].length();j++) a+=v[i-1][j];
		a+=v[i-1][0];
		//cout << a << "\n";
		if( a==v[0] ) break;
		else v.push_back(a);
		i++;
	}
//	cout << v[0];
	//for(int i=0;i<v.size();i++) cout << v[i] << endl;
	sort(v.begin(),v.end());
	if(k>v.size()) {
		cout << -1;
		return 0;
	}
	cout << v[k-1];
	return 0;
}
