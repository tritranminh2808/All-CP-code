#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q, m; cin >> n >> q >> m;
	vector <int> a(n);
	for(int i=0;i<n;i++) a[i]=m;
	while(q--){
		int r,p,d,val=99999999;
		cin >> r >>p;
		while(p>0){
			for(int i=r-1;i>=0;i--){
				if(i==0) {
					d=0;
					break;
				}
				if(a[i-1]>a[i]){
					val=a[i-1];
					d=i;
					break;
				}
			}
			int j=d;
			while(p>0&&a[r-1]<val){
				p--;
				a[j]++;
				j++;
				if(j==r) j=d;
				
			}
		}
		
	}
	for(int i=0;i<n;i++) cout << a[i] << " ";
	
	return 0;
}
