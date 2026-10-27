#include <bits/stdc++.h>
using namespace std;
const int p=1e6+1;
int s[p],a[p];
int tinh_luc(int n, int m){
	s[m]+=a[m];
	long long dap_an=s[m];
	for(int i=m-1;i>=n;i--){
		s[i]=s[i+1]+a[i];
		dap_an+=s[i];
	}
	return dap_an;
}
int main(){
//	freopen("CAY_RUONG.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test; cin >> test;
	
	for(int i=0;i<test;++i){
		int n; cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		int t;cin >> t;
		for(int i=0;i<t;i++){
			for(int i=0;i<n+1;i++) s[i]=0;
			int a,b;
			cin >> a >> b;
			cout << tinh_luc(a-1,b-1)%1000000007 << "\n";
		}
	}
	
	return 0;
}
