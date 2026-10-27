#include <bits/stdc++.h>
using namespace std;
const long long p=1e3+3;
long long s[p][p];
int main(){
	long long n; cin >> n;
	for(long long i=0;i<=n;i++) s[i][0]=1;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i>j) s[i][j]=s[i-1][j];
			else s[i][j]=s[i-1][j]+s[i][j-i];
			//cout << i << " " << j << ": " << s[i][j] << endl;
		}
	}
	cout << s[n][n];
	return 0;
}
