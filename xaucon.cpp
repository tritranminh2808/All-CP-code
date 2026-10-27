#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int find(int a){
	int i=0;
	while(((1<<i)-1)*3<=a) i++;
	return (1<<(i-1));
}
bool sech[200005];
//int k[200005];
int sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
	while(q--){
		int sol=0;
		int n; cin >> n;
//		for(int i=0;i<=n;i++) k[i]=0;
		string s; cin >> s;
		for(int i=1;i<=n;i++) sech[i]=s[i-1]-'0';
		int k=n+1;
		for(int i=n;i>=1;--i){
			if(sech[i]==1) k=i;
			if(k!=n+1){
				int x=0;
				for(int r=k;r<=min(n,k+18);r++){
					x+=sech[r];
					if(x==r-i+1) sol++;
					x*=2;
				}
			}
		}
		cout << sol << "\n";
	}
	return 0;
}
