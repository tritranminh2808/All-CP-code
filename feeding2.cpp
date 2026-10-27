#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e6+5;
int a[p],x[p],n;
int minn[p];
int sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	int n,k; cin >> n>>k;
	//minn[n]=n;
	for(int i=1;i<=n;i++) cin >>x[i];
	for(int i=1;i<=n;i++) cin >>a[i];
	deque<int> dq;
//	for(int i=n;i>n-k+1;i--) dq.push_back(i);
	for(int i=1;i<=n;i++){
		while(!dq.empty()&&a[dq.back()]>a[i]) dq.pop_back();
		dq.push_back(i);
		if(dq.front()<=i-k) dq.pop_front();
		minn[i]=dq.front();
	}
	for(int i=1;i<=n;i++) sol+=x[i]*a[minn[i]];
	cout <<sol;
	return 0;
	
}
