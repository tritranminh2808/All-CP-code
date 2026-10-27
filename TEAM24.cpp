#include <bits/stdc++.h>
using namespace std;
long long sol=0;
const long long p=1e6+5;
long long a[p];
int r[p],l[p];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n; cin >> n;
	for(long long i=1;i<=n;i++) cin >> a[i];
	stack <int> st;stack <int> st1;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[i]>a[st.top()]) st.pop();
		if(st.empty()) l[i]=0;
		else l[i]=st.top();
		st.push(i);
	}
	for(int i=n;i>=1;i--){
		while(!st1.empty()&&a[i]>a[st1.top()]) st1.pop();
		if(st1.empty()) r[i]=n+1;
		else r[i]=st1.top();
		st1.push(i);
	}
	for(int i=1;i<=n;i++){
		sol=sol+i-l[i]-1+r[i]-i-1;
	//	cout << l[i] << " " << r[i] << endl;
	}
	cout << sol;
	return 0;
}
