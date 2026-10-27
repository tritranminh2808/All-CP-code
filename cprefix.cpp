#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,c=31;
const int pp=1e5+5;
int power[pp],hashT[pp],sol[pp];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	s=" "+s;
	power[0]=1;
	for(int i=1;i<=100004;i++) power[i]=power[i-1]*c%mod;
	for(int i=1;i<s.length();i++) hashT[i]=(hashT[i-1]*c+s[i]-'a'+1)%mod;
	vector <int> luu;
	for(int i=1;i<2;i++){
		int ht=(hashT[i]-power[i]*hashT[0])%mod;
		if(ht<0) ht+=mod;
		for(int j=1;j<s.length()-i+1;j++){
			int ht2=(hashT[j+i-1]-power[i]*hashT[j-1])%mod;
			if(ht2<0) ht2+=mod;
			if(ht2==ht) {
				sol[i]++;
				luu.push_back(j);
			}
		}
	}
	for(int i=2;i<s.length();i++){
	/*	for(auto i : luu) cout << i << " ";
			cout << endl;*/
		int ht=(hashT[i]-power[i]*hashT[0])%mod;
		if(ht<0) ht+=mod;
		vector <int> vec;
		for(int j=0;j<luu.size();j++){
			if(luu[j]>=s.length()-i+1) continue;
			int ht2=(hashT[luu[j]+i-1]-power[i]*hashT[luu[j]-1])%mod;
			if(ht2<0) ht2+=mod;
			if(ht2==ht){
				sol[i]++;
				vec.push_back(luu[j]);
			}
		}
		luu=vec;
	}
//	
	for(int i=1;i<s.length();i++) cout << sol[i] << " ";
	return 0;
}
