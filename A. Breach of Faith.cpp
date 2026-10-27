#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(2*n);
//		unordered_map<int,bool> mp;
		for(int i=0;i<2*n;i++) cin>> a[i];
		sort(a.begin(),a.end(),cmp);
		vector <int> sol(2*n+1);
		sol[0]=a[0];
		int _2n1=0,schan=0,sle=0,ind=2;
		for(int i=1;i<2*n;i++){
			sol[ind]=a[i];
			ind+=2;
			if(ind>2*n+1) ind =1;
		}
		for(int i=0;i<2*n+1;i++) {
			if(i%2==0) sle+=sol[i];
			else schan+=sol[i];
		}
		sol[2*n-1]=-schan+sle;
		for(int i=0;i<2*n+1;i++) cout << sol[i] << " "
;		cout << "\n";
	}
	return 0;
}
