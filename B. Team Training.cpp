#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],l[1000005],r[1000005];
bool cmp(int a, int b){
	return a>b;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>> t;
	while(t--){
		int n,k;cin >> n>>k;
		vector <int> a(n);
//		int zer=3,two=2,one=1,three=1,five=1;
		for(int i=0;i<n;i++) cin >> a[i];
		sort(a.begin(),a.end(),cmp);
		int sol=0,s=0,minc=1e18,cnt=0;
		for(int i=0;i<n;i++){
			cnt++;
			if(a[i]*cnt>=k){
				cnt=0;
				sol++;
			}
		}
		cout << sol << "\n";
	}
	return 0;
}
