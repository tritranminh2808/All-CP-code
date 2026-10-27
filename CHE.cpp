#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("CHE.INP","r+",stdin);
	freopen("CHE.OUT","w+",stdout);
	int k; cin >> k;
	string s;cin >> s;
	int a=0,b=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A') a++;
		else b++;
	}
	if(a>b) cout << ">";
	else if(a<b) cout << "<";
	else cout << "=";
	return 0;
}
