#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int x,n,k; cin>> x >> n >> k;
		int base=k;
		vector <int> sech;
		while(x!=0){
			sech.push_back(x%2);
			x/=2;
		}
		int d1=0;
		reverse(sech.begin(),sech.end());
		for(int i=sech.size()-1;i>=0;i--){
			if(sech[i]==0) continue;
			d1++;
		}
//		cout << d1;
		if(d1+k>n) cout << -1;
		else{
	//		for(auto i : sech) cout << i;
			int p=0;
			int pre=0;
			int sol=0;
			for(int i=sech.size()-1;i>=0;i--){
				if(k==0) break;
				if(sech[i]==0) {
					p++;
					k--;
					sol+=pre;
				}
				else pre++;
			}
			sol+=pre*(base-p);
			cout << sol;
			//else cout << -1;
		}
		cout << "\n";
	}
	return 0;
}

