#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	vector <int> v;
	for(int i=1;i<4;i++){
		int k; cin >> k;
		v.push_back(k);		
	}
	sort(v.begin(),v.end());
	if(v[1]-v[0]==v[2]-v[1]){
		if(v[0]-(v[1]-v[0])>0) cout << v[0]-(v[1]-v[0]);
		cout << " " << v[2]+(v[1]-v[0]);
		return 0;
	}
	int k=v[1]-v[0];
	if(v[2]-v[1]!=k){
		if(k<v[2]-v[1]) cout << v[1]+k;
		else cout << v[0]+v[2]-v[1];
		return 0;
	}
//	cout << v[0]-k << " " << v[2]+k;
}

