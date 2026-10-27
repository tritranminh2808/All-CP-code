#include <bits/stdc++.h>

using namespace std;
bool cmp(long long  a,long long  b){
	return a>b;
}
const long long  N = 1e6 + 1;
long long a[N];
long long max1=-1e9-1,max2=-1e9-1,min1=1e9+1,min2=1e9+1,sol=0;
int  main()
{
    long long  n,k;cin >> n>>k;
    for(long long  i=0;i<n;i++) cin >> a[i];
    sort (a+1,a+n,cmp);
    for(long long  i=0;i<n;i++){
    	if(k>=0) {
    	//	cout << a[i];
    		sol+=a[i];
    		k--;
		}
		else sol-=a[i];
	}
    cout << sol;
}
