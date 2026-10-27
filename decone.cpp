#include <bits/stdc++.h>
//#define int long long
using namespace std;
int a[1000005],l[1000005],r[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; 
//	vector <int> a;
	for(int i=1;i<=n;i++) cin>> a[i];
	stack<int> S;
	for(int i=1;i<=n;i++){
		while(!S.empty()&&a[S.top()]>=a[i]) S.pop();
		if(S.empty()) l[i]=0;
		else l[i]=S.top();
		S.push(i);
	}
	while(!S.empty()) S.pop();
	for(int i=n;i>=1;i--){
		while(!S.empty()&&a[S.top()]>=a[i]) S.pop();
		if(S.empty()) r[i]=n+1;
		else r[i]=S.top();
		S.push(i);
	}
	long long res = 0;
	map<pair<int, int > , bool> mp;
	for (int i = 1; i <= n; ++i)
	{
//		cout << l[i] << " " << r[i] << endl;
		if(mp[{l[i],r[i]}]!=1) res+=a[i]-max(a[l[i]],a[r[i]]);
		mp[{l[i],r[i]}]=1;
	}
	cout << res ;
	
	return 0;
}
