#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],l[1000005],r[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>> t;
	while(t--){
		int n;cin >> n;
		vector <int> a(n+1);
		int zer=3,two=2,one=1,three=1,five=1;
		for(int i=1;i<=n;i++) cin >> a[i];
		int sol=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3) three--;
			if(a[i]==0) zer--;
			if(a[i]==2)two--;
			if(a[i]==1) one--;
			if(a[i]==5) five--;
			if(zer<=0&&one<=0&&two<=0&&three<=0&&five<=0)break;
			sol++;
		}
		if(sol==n) cout << 0;
		else cout << sol+1;
		cout << "\n";
	}
	return 0;
}
