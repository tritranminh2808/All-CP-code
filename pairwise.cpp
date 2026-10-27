#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("pairwise.inp","r",stdin);
	freopen("pairwise.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	vector <int> a;
	int n; cin>> n;
	for(int i=0;i<n;i++){
		int k;cin >>k;
		a.push_back(k);
	}
	int sol=n-1;
	for(int i=0;i<n-2;i++){
		int maxx=a[i+1];
		if(maxx>a[i]) continue;
		for(int j=i+2;j<n;j++){
			if(a[j]>=maxx){
				sol++;
				maxx=a[j];
			}
			if(a[j]>a[i]) break;
		}
	//	cout << i << " " << sol << "\n";
	}
	cout << sol;
}
