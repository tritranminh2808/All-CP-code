#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int sol=1;
signed main(){
	freopen("treewalk.inp","r",stdin);
	freopen("treewalk.out","w",stdout);
	int ind=1;
	string s; cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='L')	sol=sol*2%mod;
		else if(s[i]=='R') sol=(sol*2+ind)%mod;
		else{
			sol=(sol*5+ind)%mod;
			ind=ind*3%mod;
		}
	}
	cout << sol;
	return 0;
}
