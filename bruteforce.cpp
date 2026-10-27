#include <bits/stdc++.h>
#define int long long
using namespace std;
int c=257;
const int mod=1e9+7;
int hash1[1000005], hash2[1000005],power[1000005];
string a;
int n;
int dem[100005];
bool check(int l, int r){
	int r2=n-l+1,l2=n-r+1;
	long long memaybeo=(hash1[r]-hash1[l-1]*power[r-l+1])%mod,bomaygay=(hash2[r2]-hash2[l2-1]*power[r2-l2+1])%mod;
	if(memaybeo<0) memaybeo+=mod;
	if(bomaygay<0) bomaygay+=mod;
	if(bomaygay==memaybeo) return true;
	return false;
}
bool check2(int l1, int r1, int l2, int r2){
	long long memaybeo=(hash1[r1]-hash1[l1-1]*power[r1-l1+1])%mod,bmg=(hash1[r2]-hash1[l2-1]*power[r2-l2+1])%mod;
	if(memaybeo<0) memaybeo+=mod;
	if(bmg<0) bmg+=mod;
	if(bmg==memaybeo) return false;
	return true;
}
int res=0,cnt=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	power[0]=1;
	for(int i=1;i<=1e6; i++) power[i] = power[i-1]*c%mod;
	cin >> a;
	n=a.length();
	a=' '+a+' ';
	for(int i=1;i<=n;i++) 
	for(int i=1;i<=n;i++) hash1[i]=(hash1[i-1]*c+a[i]+1)%mod;
	reverse(a.begin(),a.end());
	for(int i=1;i<=n;i++) hash2[i]=(hash2[i-1]*c+a[i]+1)%mod;
	for(int len=1;len<=n/2;len++){
		for(int i=1;i<=n;i++){
			if(check(i,i+len-1)){
				if(i+2*len-1>n) continue;
				if(check(i+len,i+2*len-1))
			}
		}
	}
	if(res==0){
		cout << -1;
		return 0;
	}
	cout << res << " " << cnt;
	return 0;
}

