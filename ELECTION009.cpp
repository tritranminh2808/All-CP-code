#include <bits/stdc++.h>
using namespace std;
bool nguyen (int n,int k){
	int p=n/k;
	if(p*k==n) return true;
	else return false;
}
int main()
{
	freopen("ELECTION009.inp","r",stdin);
	freopen("ELECTION009.out","w",stdout);
	int t;
	cin >> t;
	for(int j=0;j<t;j++){
		int n,k;
		cin >> n >> k;
		int tong=0;
		int a[n],maxn=0;
		for(int i=0;i<n;i++) {
			cin >> a[i];
			tong+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(nguyen(tong+k,n)==false) cout << "NO\n";
		else {
			if((tong+k)/n<maxn) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}
