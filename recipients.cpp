#include <bits/stdc++.h>
#define int long long
int x[1000005];
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n >> m;
	while(m--){
		int a,k; cin >> a >> k;
		if(k+a-1<=n){
			x[k]++;
			x[k+a]--;
		}
		else{
			a-=(n-k+1);
			x[k]++;
			x[n+1]--;
			int p=a/n;
			x[1]+=p;
			x[n+1]-=p;
			a%=n;
			x[1]++;
			x[a+1]--;
		}
	}
	int sol=-1e18,cnt=0;
	for(int i=1;i<=n;i++) {
		x[i]+=x[i-1];
		sol=max(sol,x[i]);
	}
	for(int i=1;i<=n;i++) if(x[i]==sol) cnt++;
	cout << sol << " " << cnt;
	return 0;
}

