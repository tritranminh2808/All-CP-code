#include <bits/stdc++.h>
using namespace std;
bool cmp(string x, string y){
	return x.length()>y.length();
}
int main(){
	freopen("cau48.inp","r",stdin);
	vector <string> a;
	string s;
	while(cin>> s) a.push_back(s);
	sort(a.begin(),a.end(), cmp);
	cout << a[0];
	return 0;
}
