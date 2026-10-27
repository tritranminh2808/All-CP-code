#include <bits/stdc++.h>
#define int long long
int dp[100005],dp2[100005];
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin >> n >> q;
	string s;
	cin>> s;
	vector <int> a(n+1);
	for(int i=1;i<=n;i++)a[i]=s[i-1]-'A'+1;
	stack<int> S;
	int res=0;
	for (int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1];
		while (!S.empty()&&S.top()>a[i]) S.pop(); 
		if (a[i]>0 &&(S.empty()||S.top()<a[i])) dp[i]++; 
		S.push(a[i]);
	}
	while(!S.empty()) S.pop();
	for(int i=n;i>=1;i--){
		dp2[i]=dp2[i+1];
		while(!S.empty()&&S.top()>a[i]) S.pop();
		if(a[i]>0&&(S.empty()||S.top()<a[i])) dp2[i]++;
		S.push(a[i]);
	}
//	for(int i=1;i<=n;i++) cout<< dp[i] <<" ";
	while(q--){
		int l,r; 
		cin>> l >> r;
		cout << dp[l-1]+dp2[r+1]<< "\n";
	}
	
	return 0;
}
