#include <bits/stdc++.h>
using namespace std;

long long sol=0;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n; cin >>n;
	long long a[n];
	for(long long i=0;i<n;i++) cin >> a[i];
	sort (a,a+n);
	sol=a[0];
	long long k=a[0],coin=1;
	for(long long i=1;i<n;i++){
		if(a[i]>sol){
			sol+=a[i];
			k=a[i];coin++;
		}
		else {
			sol-=k;sol+=a[i];
			k=a[i];
		}
	}	
	cout << coin << " " << sol;
	return 0;
}

