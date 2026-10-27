#include <bits/stdc++.h>
#define int long long
using namespace std;
int pre[100005],a[100005];
bool cmp(int a, int b){
	return a>b;
}
signed main(){
	int n,k; cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=n;i>=1;i--) pre[i]=pre[i+1]+a[i];
	sort(pre+2,pre+n+1,cmp);
	int sol=pre[1];
	for(int i=2;i<=k;i++) sol+=pre[i];
	cout << sol;
	return 0;
}
