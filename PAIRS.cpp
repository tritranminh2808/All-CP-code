#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("pairs.inp","r",stdin);
	freopen("pairs.out","w",stdout);
	vector <int> a;
	int n; cin>> n;
	for(int i=0;i<n;i++){
		int k;cin >>k;
		a.push_back(k);
	}
	int sol=n-1;
	for(int i=0;i<n-2;i++){
		int maxx=a[i+1];
		if(maxx>=a[i]) continue;
		for(int j=i+2;j<n;j++){
			if(a[j]>maxx){
				sol++;
				maxx=a[j];
			}
			if(a[j]>=a[i]) break;
		}
	}
	cout << sol;
}
