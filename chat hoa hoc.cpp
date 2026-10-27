#include <bits/stdc++.h>
#define int long long
using namespace std;
int hh[118]={ 73,18831,19863,17289,67,68,79,80,71,20373,20369,20118,17039,21662,81,84,17553,17045,76,17542,21656,21919,87,17559,20125,
18317,17556,20377,17562,23466,18570,18574,17046,21658,17302,19615,21398,21671,90,23470,20370,20126,21913,21417,21404,20886,17034,17545,19097,
21667,21655,21915,74,22943,17560,17285,19855,17546,20900,20372,20895,21666,18076,18573,21912,17823,18841,18073,21923,23197,19875,18832,21911,
88,21401,20644,19101,20902,17048,18833,21922,20884,17293,20897,17047,21410,18330,21397,17030,21918,20883,86,20384,20903,17040,17554,17295,17547,
18074,18325,20115,20383,19872,21402,17800,21660,17292,18845,20131,17817,21403,17555,20376,18324,20114,19876,21929};
const int mod=1e9+7,base=257;
int hs(string s){
	int hh=0;
	for(int i=0;i<s.length();i++) hh=(hh*base+s[i]+1)%mod;
	return hh;
}
bool chck(string s){
	int kk=hs(s);
	for(int i=0;i<118;i++) if(hh[i]==kk) return true;
	return false;
}
bool check[2][100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
//	string x; cin >> x;
//	if(chck(x)) cout << "jgdshfgsahdgsad";
	while(q--){
		for(int i=1;i<100000;i++){
			check[0][i]=0;
			check[1][i]=0;
		}
		check[0][0]=1;
		check[1][0]=1;
		string s; cin >> s;
		int n=s.length();
		s=' '+s;
		for(int i=1;i<=n;i++){
			string mot="",hai="";
			mot+=s[i];
			hai+=s[i-1];hai+=s[i];
			if(chck(mot)) if(check[0][i-1]==1||check[1][i-1]==1) check[0][i]=1;
			if(chck(hai)) {
				if(i>1) if(check[0][i-2]==1||check[1][i-2]==1) check[1][i]=1;
			}
		}
		/*for(int i=1;i<=n;i++){
			cout << check[0][i] << " " << check[1][i] << endl;
		}	*/
		if(check[0][n]||check[1][n]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
