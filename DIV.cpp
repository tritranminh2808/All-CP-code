#include <bits/stdc++.h>
using namespace std;
long long t;
int main()
{
	freopen("DIV.inp","r",stdin);
	freopen("DIV.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n; int a[n]; for(int i=0;i<n;i++) {
		cin >> a[i];
		t+=a[i];
	}
	for(int i=t-1;i>=1;--i){
		if(t%i==0){
			int k=t/i,z=0;
			bool chck=0;
			for(int j=0;j<n;j++){
				z+=a[j];
				if(z>k) {
					chck=1;
					break;
				}
				else if(z==k){
					z=0;
				}
			}
			if(chck==0) {
				cout << i; return 0;
			}
		}
	}
	return 0;
}
