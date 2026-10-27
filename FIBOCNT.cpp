#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
unsigned long long fib[p];

int main(){
	long long n,m; cin >> n >> m;
	long long count=0;

	fib[0]=0;fib[1]=1;fib[2]=1;
	if(0>=n&&0<=m) count++;
	if(1>=n&&1<=m) count++;
	if(2>=n&&2<=m) count++;
	long long i=3;
	while(1)
	{
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>=n&&fib[i]<=m) count++;
		if(fib[i]>m) break;
		
		++i;
	}
	cout << count;
	return 0;
}
