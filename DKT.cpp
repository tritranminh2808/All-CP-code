#include <bits/stdc++.h>
using namespace std;
const int p=1e5;
bool dem[p];
int sol;
int main(){
	freopen("DKT.INP","r+",stdin);
	freopen("DKT.OUT","w+",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(dem[int(s[i])]==0){
			dem[int(s[i])]++;sol++;
		}
	}
	cout << sol;
	return 0;
}
