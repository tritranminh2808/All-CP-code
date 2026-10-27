#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=0;
bool cmp(int a, int b){
	return a>b;
}
int a[200005],p[200005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin >> n >> q;
//	vector <int> a(n+1), p(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	while(q--){
		int l, r; cin >> l >> r;
		p[l]++;
		p[r+1]--;
	}
	for(int i=1;i<=n;i++) p[i]+=p[i-1];
	sort(a+1,a+n+1,cmp);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++) sol+=a[i]*p[i];
//	for(int i=1;i<=n;i++) cout << p[i] << " ";
	cout << sol;
	return 0;
}
