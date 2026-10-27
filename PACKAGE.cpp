#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	int sol=0;
	sol+=(n/k)*(m/k);
	
	if(n%k!=0)sol+=(n/k)+1;
	cout << sol;
	if(m%k!=0) sol+=m/k;
	
}
