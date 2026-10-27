#include <bits/stdc++.h>
using namespace std;
string f[500];
string cal(string a, string b){
	if(a.length()<b.length()) swap(a,b);
	int n=a.length(),m=b.length();
//	cout << a << " " << b << "\n";
	int nho=0;
	for(int i=1;i<=m;i++){
		int x=a[n-i]-'0'+b[m-i]-'0'+nho;
//		if(b[0]=='8') cout << a[m-i];
		nho=0;
		if(x>=10) {
			x-=10;
			nho=1;
		}
		a[n-i]=char(x+48);
	}
	if(nho>0){
		if(n>m) a[n-m-1]=char(int(a[n-m-1])+1);
		else a='1'+a;
	}
	return a;
}
bool cmp(string a, string b){
	if(b.length()!=a.length()) return false;
	for(int i=0;i<a.length();i++) if(a[i]!=b[i]) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("lfib.inp","r",stdin);
	freopen("lfib.out","w",stdout);
	f[1]='1';
	f[2]='1';
	for(int i=3;i<=401;i++) f[i]=cal(f[i-1],f[i-2]);
//	cout << f[4];
//	cout << f[7] << " " << f[6];
//	for(int i=1;i<=401;i++) cout << f[i] << "\n";
	int q; cin >> q;
	while(q--){
		int a,b; cin >> a >> b;
		string s;
		cin>> s;
		if(cmp(cal(f[a],f[b]),s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
