#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, mod2=1e9+9;
using ull=unsigned long long;
ull mul(ull a, ull b, ull m){
	if(b==0) return 0;
	ull t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
int sol=0,n=0,k;
bool cmp(pair <int,int> a, pair <int, int > b){
	if(a.first==b.first) return a.second < b.second;
	return a.first < b.first;
}
void xu_li(vector < pair <int, int > > v){
	if(v.empty()) return;
	for(int i=0;i<v.size();i++){
		if(v[i].first<1) v[i].first=1;
		if(v[i].second>n-k+1) v[i].second=n-k+1;
	}
	sort(v.begin(),v.end(),cmp);
	int l=v[0].first, r=v[0].second;
	for(int i=1;i<v.size();++i){
	//	cout << v[i].first << " " << v[i].second << "\n";
		if(v[i].first>=l&&v[i].first<=r){
			r=max(r,v[i].second);
		}
		else {
			sol+=r-l+1;
			l=v[i].first;
			r=v[i].second;
		}
	}
	sol+=r-l+1;
}
int power[1000005],power2[1000005];


signed main(){
//	freopen("test.inp","r",stdin);
	const int c=31,c2=37;
	power[0] = 1;
	power2[0]=1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	for(int i = 1; i <= 1e6; i++) power2[i] = power2[i - 1] * c2 % mod2;
	string a; string b;
	getline(cin,b);
	getline (cin,a);
cin >> k;
	if(k<a.length()){
		cout << 0;
		return 0;
	}
	int lena=a.length(),lenb=b.length();
	vector <int > hashT (b.size()+5,0),hashT2(b.size()+5,0);
	a=" "+a;
	b=" "+b;
	n=b.length()-1;
	int hashP=0,hashP2=0;
	for(int i=1;i<=lena;++i)  hashP = (hashP * c + a[i]  + 1)%mod;
	for(int i=1;i<=lena;++i)  hashP2 = (hashP2 * c2 + a[i]  + 1)%mod2;
	for (int i = 1; i <= lenb; i++) hashT[i] = (hashT[i - 1] * c + b[i]  + 1) % mod;
	for (int i = 1; i <= lenb; i++) hashT2[i] = (hashT2[i - 1] * c2 + b[i] + 1) % mod2;
	vector <int> soluton;
	for(int i=1;i<=lenb-lena+1;++i){
		int kk=(hashT[i+lena-1]-hashT[i-1]*power[lena])%mod;
		int k2=(hashT2[i+lena-1]-hashT2[i-1]*power2[lena])%mod2;
		if(kk<0) kk += mod;
		if(k2<0) k2+=mod2;
		if(hashP==kk&&hashP2==k2) soluton.push_back(i);
	}
//	soluton.push_back(7623762187);
	vector <pair< int, int > > res;
	for(int i=0;i<soluton.size();i++)	res.push_back({soluton[i]+a.length()-1-k,soluton[i]});
//	for(auto i : res) cout << i.first << " " << i.second << "\n";
	xu_li(res);
	cout << sol;
	return 0;
}
