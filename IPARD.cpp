#include <bits/stdc++.h>
using namespace std;
const long long p=5005;
long long s[p][p];
int main(){
	freopen("ipard.inp","r",stdin);
	freopen("ipard.out","w",stdout);
	long long n; cin >> n;
	s[0][0]=1;
	for(long long i=1;i<=n;i++) s[i][0]=0;
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=n;j++){
			if(i>j) s[i][j]=s[i-1][j];
			else s[i][j]=(s[i-1][j]+s[i-1][j-i])%123456789;
			//cout <<s[i][j] << " ";
		}
	//	cout << endl;
	}
	cout << s[n][n];
	return 0;
}
