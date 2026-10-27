#include <bits/stdc++.h>
#define int long long
using namespace std;
int c=257;
const int mod=1e9+7;
int hash1[5000005], hash2[5000005],power[5000005];
string a,s;
int n;
int res[500005];
bool check(int l, int r){
	int r2=n-l+1,l2=n-r+1;
	long long memaybeo=(hash1[r]-hash1[l-1]*power[r-l+1])%mod,bomaygay=(hash2[r2]-hash2[l2-1]*power[r2-l2+1])%mod;
	if(memaybeo<0) memaybeo+=mod;
	if(bomaygay<0) bomaygay+=mod;
	if(bomaygay==memaybeo) return true;
	else return false;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	power[0]=1;
	for(int i = 1; i <= 1e6; i++) power[i] = power[i - 1] * c % mod;
	
	cin >> s;
//	n=s.length()*2-1;
//	bool gan=0;
	a+='_';
	for(int i=0;i<s.length();i++) {
		a+=s[i];
		a+='_';
	}
//	a[a.length()-1]=' ';
	a=' '+a+' ';
	n=a.length()-2;
//	cout << n;
	reverse(a.begin(),a.end());
	for(int i=1;i<=n;i++) hash2[i]=(hash2[i-1]*c+a[i]+1)%mod;
	reverse(a.begin(),a.end());
	for(int i=1;i<=n;i++) hash1[i]=(hash1[i-1]*c+a[i]+1)%mod;
	vector <int> sol;
	sol.push_back(1);
	for(int i=2;i<n-1;i++){
		int l=0,r=i;
//		cout <<i << ":\n";
		int maxx=0;
		while(l<=r){
			int mid=(r+l)/2;
//			cout << l << " " << r << " " << mid << " " << i-mid << " " << i+mid << "\n";
			bool sech=0;
			if(check(i-mid+1,i+mid+1)){
//				cout <<"kkk\n";
				maxx=max(maxx,mid);
				sech=1;
			}
			if(sech==0) r=mid-1;
			else l=mid+1;
			
		}
		sol.push_back(maxx);
	}
	for(auto i: sol) cout <<i << " ";
	return 0;
}
