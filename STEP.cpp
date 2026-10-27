#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("step.inp","r",stdin);
	freopen("step.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;cin >> n >> q;
	vector <bool> v;
	bool check=0;
	for(int i=0;i<n;i++){
		int k; cin >> k;
		if(check ==0){
			while(k--) v.push_back(0);
			check=1;
		}
		else {
			while(k--) v.push_back(1);
			check=0;
		}
	}
	while(q--){
		int l;
		cin >> l;
		if(v[l]==0) v[l]=1;
		else v[l]=0;
		int dem=1,luu=1;
		for(int i=1;i<v.size();i++){
			if(v[i]==v[i-1]){
				luu++;
				dem=max(dem,luu);
			}
			else luu=1;
		}
		cout << dem << "\n";
	}
}
