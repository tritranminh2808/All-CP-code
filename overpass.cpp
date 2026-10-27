#include <bits/stdc++.h>
using namespace std;
int lf[1000005],rt[1000005];
int main(){
	freopen("overpass.inp","r",stdin);
	freopen("overpass.out","w",stdout);
	int n; cin >> n;
	string s; cin >> s;
	s='!'+s;
	rt[0]=1;
	lf[0]=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='L') {
			lf[i]=min(lf[i-1]+1,rt[i-1]+1);
			rt[i]=min(rt[i-1],lf[i-1]+2);
		}
		else if(s[i]=='R') {
			lf[i]=min(lf[i-1],rt[i-1]+2);
			rt[i]=min(rt[i-1]+1,lf[i-1]+1);
		}
		else {
			lf[i]=min(lf[i-1]+1,rt[i-1]+2);
			rt[i]=min(rt[i-1]+1,lf[i-1]+2);
		}
	}
	cout << min(lf[n]+1,rt[n]);
	return 0;
}
