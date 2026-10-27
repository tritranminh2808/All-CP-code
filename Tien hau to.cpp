#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,c=31;
const int pp=1e5+5;
int power[pp],hashT[pp],sol[pp];
signed main(){
	string s; cin >> s;
	s=" "+s;
	int n=s.length();
	power[0]=1;
	for(int i=1;i<=100004;i++) power[i]=power[i-1]*c%mod;
	for(int i=1;i<=n;i++) hashT[i]=(hashT[i-1]*c+s[i]-'a'+1)%mod;
	vector <int> luu;
	if(1==1){
		int ht=(hashT[1]-power[1]*hashT[0])%mod;
		if(ht<0) ht+=mod;
		for(int j=1;j<s.length();j++){
			int ht2=(hashT[j]-power[1]*hashT[j-1])%mod;
			if(ht2<0) ht2+=mod;
			if(ht2==ht) {
				sol[1]++;
				luu.push_back(j);
			}
		}
	}
	for(int i=2;i<=n;i++){
	/*	for(auto i : luu)  << i << " ";
			 << endl;*/
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
//	for(int i=1;i<n;i++)  << sol[i] << " ";
	vector <int> sech;
	for(int i=1;i<n;i++){
//		cout << s[i];
		int k1=(hashT[i]-hashT[0]*power[i])%mod;
		int k2=(hashT[n-1]-hashT[n-1-i]*power[i])%mod;
		if(k1<0)k1+=mod;
		if(k2<0)k2+=mod;
		if(k1==k2) sech.push_back(i);
	}
	cout << sech.size() << "\n";
	for(auto i : sech) cout << i << " " << sol[i] << "\n";
	return 0;
}
