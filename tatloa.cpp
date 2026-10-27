#include <bits/stdc++.h>
#define int long long
using namespace std;
int pre[100005],a[100005];
signed main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	int sol=72163787213;
	for(int ii=0;ii<12;ii++){
		int tong=ii,luu=ii,t=0;
		for(int i=1;i<=n;i++){
			t=(luu-a[i]+12)%12;
			tong+=t;
			luu=t;
		}
		sol=min(sol,tong);
	}
	cout << sol;
	return 0;
}
