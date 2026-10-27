#include <bits/stdc++.h>

using namespace std;
long long sol=0;
int main() {
    
	long long b,n;
	cin >> b >> n;
	for(int m=1;m<=2*n;m++){
		if(m!=n){
			if((2*b*m*n-b*m*m)%(n*n)==0) sol++;
		}
	}
	cout << sol;
    return 0;
}

