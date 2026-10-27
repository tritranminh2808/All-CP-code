#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("molecule.inp","r",stdin);
	freopen("molecule.out","w",stdout);
	string a;
	cin >> a;
	int d=0;
	for(int i=0;i<a.length();i++) {
		if(a[i]!=a[i+1]) d++;
	}
	int mid=(d-1)/2;
	if(a[0]==a[a.length()-1]) cout << max(0,mid-1);
	else cout << mid;
	return 0;
}
