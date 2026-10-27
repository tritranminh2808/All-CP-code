#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("gems.inp","r",stdin);
	freopen("gems.out","w",stdout);
	int n,k; cin >> n >> k;
	vector <int> v;
	for(int i=0;i<n;i++){
		int p;cin >> p;
		v.push_back(p);
	}
	sort(v.begin(),v.end());
	int sol=1;
	int i=0;
	while(lower_bound(v.begin()+i+1,v.end(),v[i]+k)!=v.end()){
		
		sol++;
		i=lower_bound(v.begin()+i+1,v.end(),v[i]+k)-v.begin();
	}
	cout << sol;
	return 0;
}
