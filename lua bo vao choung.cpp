#include <bits/stdc++.h>
using namespace std;
long long sol=0;
const int p=1e5+5;
int a[p],pre[p];
int main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	long long cnt=0;
	for(int i=1;i<=n;i++){
//		cnt+=a[i]-1;
		pre[i]=pre[i-1]+a[i]-1;
	}
	int sech=928349213;
	for(int i=1;i<=n;i++) sech=min(sech,pre[i]);
	for(int i=1;i<=n;i++) sol+=(pre[i]-sech)*(pre[i]-sech);
	cout << sol;
	return 0;
}
