#include <bits/stdc++.h>
#define int long long
using namespace std;
int m,n;
int a[1005][1005],minhag[1005][1005],maxhag[1005][1005];        
signed main(){
	int n,m; cin >> n >> m;
	int sol=(int)sqrt(m)-(int)sqrt(n);
	int k=sqrt(n);
	if (k*k==n) sol++;
	cout << sol; 
}
