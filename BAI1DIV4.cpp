#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t ; cin >> t;
	while(t--){
		int n,k;cin >> n >> k;
		vector <int> a(n);
		int s=0,cz=0;
		for(int i=0;i<n;i++) {
			cin >> a[i];
			s+=a[i];
			if(a[i]==0) cz++;
		}
		cout << min(s,cz) << endl;
	}
	return 0;
}
