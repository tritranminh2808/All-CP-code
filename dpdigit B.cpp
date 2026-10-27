#include <bits/stdc++.h>
//#define int short
using namespace std;
int k;
string p,s;
const int mod=1e9+7;
int f[100005][2][101];
int backtrack(int id,bool l,int sum){
//	cout << p << "\n";
	if(id==s.size()){
		if(sum%k==0) return 1;
		return 0;
	}
	int &a=f[id][l][sum];
	if(a!=-1) return a;
	a=0;
	for(int i=0;i<=9;i++){
		if(l||i<=s[id]-'0') a=(a+backtrack(id+1,l||i<s[id]-'0',(sum+i)%k))%mod;
	}
	return a;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	cin >> k;
	for(int i=0;i<=100000;++i){
		for(int j=0;j<=100;j++){
			f[i][0][j]=-1;
			f[i][1][j]=-1;
		}
	}
	cout << (backtrack(0,0,0)-1+mod)%mod;
//	cout << sol;
	return 0;
}
