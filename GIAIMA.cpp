#include <bits/stdc++.h>
using namespace std;
int  t;
int chck;
int main()
{
	freopen("GIAIMA.INP","r+",stdin);
	freopen("GIAIMA.OUT","w+",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	vector <int> v;
	int l=s.length();
	for(int i=0;i<s.length();i++)t+=int(s[i])-48;
	for(int i=0;i<s.length();i++) {
		v.push_back(int(s[i])-48);
		if(s[i]=='0') {
			chck++;
		}
	}
	
	if(chck==0){
		cout << "-1";
		return 0;
	}
	
	 
	else if(t%3!=0){
		cout << "-1";
		return 0;
	}
	
	else{
		sort(v.begin(),v.end());
		for(int i=v.size()-1;i>=0;i--) cout << v[i];
		
	}
	
	return 0;
}
