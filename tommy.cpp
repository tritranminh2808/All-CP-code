#include <bits/stdc++.h>
#define int long long
using namespace std;
const int pp=1e7+5;
bool check[pp];
int dem[pp],pre[pp];
void tien_xu_li(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) dem[i]++;
		while(n%i==0) n/=i;
	}
	if(n!=1) dem[n]++;
}
int a[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		tien_xu_li(a[i]);
	}
	for(int i=2;i<pp;++i){
		pre[i]=pre[i-1]+dem[i];
	}
	//for(int i=0;i<15;i++) cout << pre[i] << "\n";
	int t; cin >> t;
	while(t--){
		int l,r; cin >> l >> r;
		if(r>=pp) r=pp-1;
		cout << pre[r]-pre[l-1] << "\n";
	}
	
}
