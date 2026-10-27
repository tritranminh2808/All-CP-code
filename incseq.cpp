#include <bits/stdc++.h>
using namespace std;
const long long p=1e7+1;
long long a[p];
long long f[p],e[p];
int main(){
	long long n; cin >> n;
	for(long long i=0;i<n;i++) cin >> a[i];
	reverse(a,a+n);
	long long sol=0;
	for(int i=0;i<n;i++){
		f[i]=upper_bound(e,e+sol,a[i])-e;
		if(f[i]>=sol) sol++;
		e[f[i]]=a[i];
	}
	cout << sol;
}
