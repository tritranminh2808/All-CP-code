#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")
using namespace std;
const long long p=1e4+5;
bool a[p][p];
long long n;
long long sol=0;
int main(){
	freopen("rectarea.inp","r",stdin);
	freopen("rectarea.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	long long maxx=-1e5;
	while(n--){
		long long x,y,z; cin >> x >> y >> z;
		maxx=max(maxx,max(x,max(y,z)));
		for(long long i=0;i<z;i++){
			for(long long j=x;j<y;j++) a[i][j]=1;
		}
	}
	for(long long i=0;i<maxx+1;++i){
		for(long long j=0;j<maxx+1;++j){
			if(a[i][j]==1) sol++;
		}
	}
	cout << sol;
	return 0;
}
