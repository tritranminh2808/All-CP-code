#include <bits/stdc++.h>
using namespace std;
long long sol=1;
long long f(long long a){
	return (a/2)*(a/10+1) - (5*(a/10)*(a/10+1))/2;
}
int main(){
	long long t; cin >> t;
	while(t--){
		long long n; cin >> n;
		if(n==1) cout << 1 << endl;
		else if(n==2||n==3) cout << 2 << endl;
		else if (n==4) cout << 3 << endl;
		else if (n==5)cout << 4 << endl;
		else 
		{
			long long sol=n/5+1;
			cout << sol+f(n)+f(n-5) << "\n";
		}
	}
 	return 0; 
}
