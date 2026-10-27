#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,c=31;
const int pp=1e5+5;
int power[pp],hashT[pp],hash1[pp],sol[pp];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	string s1=s;
	reverse(s1.begin(),s1.end());
	s1=' '+s1;
	s=" "+s;
	power[0]=1;
	for(int i=1;i<=100004;i++) power[i]=power[i-1]*c%mod;
	for(int i=1;i<s.length();i++) hashT[i]=(hashT[i-1]*c+s[i]-'A'+1)%mod;
	for(int i=1;i<s1.length();i++) hash1[i]=(hash1[i-1]*c+s1[i]-'A'+1)%mod;
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
	vector <int> hh;
	for(int i=1;i<s.length();i++){
		int k1=hashT[i];
		int k2=(hashT[s.length()-1]-hashT[s.length()-1-i]*power[i])%mod;
		if(k2<0)k2+=mod;
		if(k1==k2) hh.push_back(i);
	}
	cout << hh.size() << "\n";
	for(auto i : hh) {
		cout << i  << " ";
		int xx=0;
		int base=hashT[i];
		for(int j=i+1;j<s.length();j++){
			int kk=(hashT[j]-hashT[j-i]*power[i])%mod;
			if(kk<0) kk+=mod;
			if(kk==base) xx++;
		}
		cout << xx+1 << "\n";
	}
//	for(int i=1;i<s.length();i++) cout << sol[i] << " ";
	return 0;
} 
