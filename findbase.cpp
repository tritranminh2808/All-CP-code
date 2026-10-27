#include <bits/stdc++.h>
#define int ull
using ull=unsigned long long;
using namespace std;
long long e[65] = {0,1000000000000000000, 1000000000, 1000000, 31622, 3981, 1000, 372,177, 100, 63, 43, 31, 24, 19, 15, 13, 11, 10, 8, 7, 7, 6, 6, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1};
int cal(int x, int mu){
	int ss=1;
	for(int i=1;i<=mu;i++) ss*=x;
	return ss;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int sol=0;
		bool sech=0;
		for(int i=64;i>=1;i--){
			int l=1,r=e[i];
			while(l<=r){
				int mid=(l+r)/2;
				int x=cal(mid,i);
				if(x<n) l=mid+1;
				else if(x>n) r=mid-1;
				else {
					sol=mid;
					sech=1;
					break;
				}
			}
			if(sech==1) break;
		}
		cout << sol <<"\n";
	}
}
