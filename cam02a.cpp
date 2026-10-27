#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	vector <int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	deque <int> dq;
	int sol=-1,cnt=0;
	for(int i=0;i<m;i++) cnt+=a[i];
	if(a[m-1]-a[0]<=k)sol=max(sol,cnt);
	for(int i=m;i<n;i++){
		cnt-=a[i-m];
		cnt+=a[i];
		if(a[i]-a[i-m+1]<=k) sol=max(sol,cnt);
	}
	if(sol!=-1)cout << sol;
	else cout << "Ken ca chon canh";
}

