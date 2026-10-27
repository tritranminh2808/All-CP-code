#include <bits/stdc++.h>
using namespace std;
long long sol=1;
int main(){
	long long n;cin >> n;
	long long a[n];
	 for(int i=0;i<n;i++) {
	 	cin >> a[i];sol*=a[i];
	 }
	int i=2;
	while(1){
		if(sol%i!=0){
			cout << i ;return 0;
		}
		i++;
	}
 	return 0; 
}
