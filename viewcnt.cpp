#include <bits/stdc++.h>
#define int long long 
using ll=long long;
using namespace std;
int l[100005],r[100005],a[100005];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	string s; cin >> s;
	stack <int> st; 
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
		int end=0;
		if(!st.empty()) end=st.top();
		r[end]++;
		r[i]--;
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
		int end=n+1;
		if(!st.empty()) end=st.top();
		l[i+1]++;
		l[end+1]--;
		st.push(i);
	}
	for(int i=1;i<=n;i++) {
		l[i]+=l[i-1];
		r[i]+=r[i-1];
		if(s[i-1]=='L') cout << l[i] << " ";
		else cout << r[i] << " ";
	}
	return 0;
	
}
