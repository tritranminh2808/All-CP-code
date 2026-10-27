#include <bits/stdc++.h>
//#define int short
using namespace std;
int id=0,sol=0;
string p,s;
const int mod=1e9+7;
int f[5001][2][5001];
int backtrack(int id,bool l,int sum){
//	cout << p << "\n";
	if(id==s.size()){
		if(sum==0) return 1;
		return 0;
	}
	int &a=f[id][l][sum];
	if(a!=-1) return a;
	a=0;
	if(l||s[id]>='(') a+=backtrack(id+1,l||s[id]>'(',sum+1)%mod;
	if((l||s[id]>=')')&&sum>=1) a+=backtrack(id+1,l||s[id]>')',sum-1)%mod;
	return a;
	
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for(int i=0;i<=5000;++i){
		for(int j=0;j<=5000;j++){
			f[i][0][j]=-1;
			f[i][1][j]=-1;
		}
	}
	cout << backtrack(0,0,0);
//	cout << sol;
	return 0;
}
