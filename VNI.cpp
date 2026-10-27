#include <bits/stdc++.h>
using namespace std;

int main()
{ 
	freopen ("VNI.inp","r",stdin);
	freopen ("VNI.out","w",stdout);
	long long n; cin >> n;
	long long a[n];
	for(long long i=0;i<n;i++)cin >> a[i];
	long long m; cin >> m;long long b[m]; 
	for(long long i=0;i<m;i++) cin >> b[i];
	long long s[n],k[n];
	s[n-1]=0;
	long long max=a[n-1];
	for(long long i=n-2;i>=0;i--){
		if(a[i]>max) {
			max=a[i];
			s[i]=0;
		}
		else{
			s[i]=max-a[i];
		}
	}
	for (long long i=n-2; i>=0; i--)	s[i] += s[i+1];
	for(long long i=0;i<m;i++) cout << s[b[i]-1] <<"\n"; 
	return 0;
}
