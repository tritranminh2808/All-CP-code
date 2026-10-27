#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int dp[1000005];
int find(int n){
	int k=-1;
	while(n!=0){
		k=max(k,n%10);
		n/=10;
	}
	return k;
}
int sol=0;
signed main(){
	int n; cin >> n;
	while(n!=0){
		n-=find(n);
		sol++;
	}
	cout << sol;
}
