#include <bits/stdc++.h>
using namespace std;
long long  sol=0;
const long long  p=1e6+5;
long long  dem[p];
int   main(){
	long long   n,k;
	cin >> n>>k;
	long long  a[n];
	for(long long  i=0;i<n;i++)  {
		cin >> a[i];dem[a[i]+1000]++;
	}
	for(long long  i=0;i<n;i++){
		
		sol+=dem[a[i]+k+1000];
		if(k==0) sol--;
	//	if(a[i]>=k) sol+=dem[a[i]-k];
	//	cout << sol << " ";
	}
	cout << sol;
	return 0;
}
