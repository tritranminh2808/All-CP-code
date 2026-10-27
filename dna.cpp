#include <bits/stdc++.h>
#define int long long
using namespace std;
const int z=1e5+5;
int a1[z],t1[z],c1[z],a2[z],t2[z],c2[z],hash1[z],hash2[z];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin>> n>>q;
	string a,b; cin >> a >> b;
	a='!'+a;
	b='!'+b;
	for(int i=1;i<=n;i++) {
		a1[i]=a1[i-1];
		c1[i]=c1[i-1];
		t1[i]=t1[i-1];
		if(a[i]=='A') a1[i]++;
		if(a[i]=='C') c1[i]++;
		if(a[i]=='T') t1[i]++;
	}
	for(int i=1;i<=n;i++) {
		a2[i]=a2[i-1];
		c2[i]=c2[i-1];
		t2[i]=t2[i-1];
		if(b[i]=='A') a2[i]++;
		if(b[i]=='C') c2[i]++;
		if(b[i]=='T') t2[i]++;
	}
	
	while(q--){
		int l,r; cin >> l >> r;
		l++;r++;
		int sol=0;
//		int s1=a1[r]-a1[l-1]+t1[r]-t1[l-1]+c1[r]-c1[l-1];
//		int s2=a2[r]-a2[l-1]+t2[r]-t2[l-1]+c2[r]-c2[l-1];
		if(a1[r]-a1[l-1]!=a2[r]-a2[l-1]||t1[r]-t1[l-1]!=t2[r]-t2[l-1]||c1[r]-c1[l-1]!=c2[r]-c2[l-1]) cout << -1;
		else{
			for(int i=l;i<=r;i++){
				if(a[i]!=b[i]){
					for(int j=i+1;j<=r;j++){
						if(a[i]==b[j]&&a[j]!=b[j]){
							swap(a[i],b[j]);
							sol++;
							break;
						}
					}
				}
			}
			cout << sol;
		}
		cout << "\n";
	}
}
