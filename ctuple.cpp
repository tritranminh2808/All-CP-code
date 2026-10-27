#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=0;
int C[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d,x;cin >> a >> b >> c >> d >> x;
	for(int i=1;i<=a;++i){
		for(int j=1;j<=b;j++) C[i*j]++;
	}
	for(int i=1;i<=1000000;i++) C[i]+=C[i-1];
	for(int i=1;i<=c;++i){
		for(int j=1;j<=d;j++) {
			if(i*j>x) break;
			int k=x/i/j;
			if(k>1e6) k=1000000;
			sol+=C[k];
		}
	}
	
	cout << sol;
	return 0;
}
