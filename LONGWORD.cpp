#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("LONGWORD.INP","r",stdin);
	freopen("LONGWORD.OUT","w",stdout);
	string s;
	getline(cin, s);
	int res = 0;
	int i = 0;
	int tmp = 0;
	while (i<s.size()){
		if(isalpha(s[i])){
			tmp++;
			res = max(res, tmp);
		}else tmp = 0;
		i++;
	}
	cout << res;
}
