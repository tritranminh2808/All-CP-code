#include <bits/stdc++.h>
#define int long long
using namespace std;
int A,B;
signed main(){
//	freopen("tesst.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a; cin >> a;
	bool x=0;
	for(int i=2;i<=sqrt(a);i++){
		while(a%i==0&&a>i){
			if(x==0){
				A+=i+a/i;
				x=1;
			}
			else {
				B+=i+a/i;
				x=0;
			}
			a/=i;
		}
	}
	cout << A -B;
	return 0;
}
