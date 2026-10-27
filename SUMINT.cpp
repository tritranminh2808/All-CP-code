#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b; cin >> a >> b;
	long long sum1=((b-a)+1)*(a+b)/2;
	if(a%2!=0) a++;
	if(b%2!=0) b--;
	long long sum2=((b-a)/2+1)*(a+b)/2;
	cout << sum1 << endl << sum2;
	return 0;
}

