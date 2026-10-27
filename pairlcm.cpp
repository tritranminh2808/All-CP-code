#include <bits/stdc++.h>
#define int long long
using namespace std;
int lcm(int a, int b){
	return a*b/__gcd(a,b);
}
signed main(){
	freopen("pairlcm.inp","r",stdin);
	freopen("pairlcm.out","w",stdout);
	int n; cin >> n;
	if(n%2==0){
		cout << n/2 << " ";
		for(int i=n/2;i>=1;i--){
			if(__gcd(i,n-i)==1){
				cout << i*(n-i);return 0;
			}
		}
	}
	int m=1e18;
	for(int i=sqrt(n);i>=1;i--){
		if(i==1){
			m=n-1;break;
		}
		if(n%i!=0) continue;
		int k=n/i;
		for(int j=1;j<=i/2;j++){
			m=min(m,lcm(k*j,k*(i-j)));
		}
		break;
	} 
	cout << m << " " << n/2*(n-n/2);
	return 0;
}
