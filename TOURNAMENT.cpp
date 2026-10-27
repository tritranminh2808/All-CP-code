#include <bits/stdc++.h>
using namespace std;
long long sol;
int main(){
	long long n; cin >> n;
	while(n!=1){
	//	cout << n << "\n";
		if(n%2==0){
			n/=2;sol++;
		}
		else n+=2*n+1;
		
	}
	cout << sol;
}
