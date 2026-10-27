#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")
using namespace std;
const long long p=1e6+5;
long long n,d;
long long a[p],b[p],dd[p];
int  main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d;
	
	for(long long i=0;i<d;i++){
		long long  l,r,k;cin >>l >> r >> k;
		b[l-1]+=k;
		b[r]-=k;
		
	}
	dd[0]=b[0];cout<< dd[0] << " ";
	for(long long  i=1;i<n;i++) {
		dd[i]=dd[i-1]+b[i];
		cout << dd[i] << " ";
		
	}
	return 0;
}

