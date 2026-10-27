#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int sol=1;
int l[1000005],r[1000005],a[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	stack<int> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) l[i]=0;
		else l[i]=st.top();
		st.push(i);
	}

	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) r[i]=n+1;
		else r[i]=st.top();
		st.push(i);
	}
	
	int sol=-1;
	for(int i=1;i<=n;i++) sol=max(sol,(r[i]-l[i]+1)*a[i]);
	cout << sol;
}

