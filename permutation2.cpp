#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector <int> v,a(n);
	for(int i=0;i<n;i++) v.push_back(i+1);
	for(int i=0;i<n;i++) cin>> a[i];
	int k; cin>> k;
	int dem=1;
	vector <int > sol;
	do{
		if(dem==k) for(auto i : v) sol.push_back(i);
		bool check=0;
		for(int i=0;i<n;i++){
			if(a[i]!=v[i]){
				check=1;
				break;
			}
		}	
		if(check==0) {
			cout << dem << "\n";
			break;
		}
		dem++;
		
	}
	while(next_permutation(v.begin(),v.end()));
	if(sol.size()>0) {
		for(auto i : sol) cout << i << " ";
		return 0;
	}
	while(dem<k) {
		next_permutation(v.begin(),v.end());
		dem++;
	}
	for(auto i : v) cout << i << " ";
	return 0;
}
