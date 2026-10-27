#include <bits/stdc++.h>
#define int long long
using namespace std;
bool scp(int a){
	int k=sqrt(a);
	if(k*k==a) return true;
	return false;
}
int pre[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=1000000;i++){
		for(int j=i;j<=1000000;j+=i)pre[j]+=i;
	}
	int q; cin >> q;
	while(q--){
		int a; cin >> a;
		cout << pre[a] << "\n";
	}
	return 0;
}
