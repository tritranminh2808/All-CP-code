#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#pragma GCC target("sse4")
using namespace std;
int sol=0;
int xu_li(vector <int> a){
	vector <int> v;
	
	bool check=false;
	v.push_back(a[0]);
	for(int i=1;i<a.size();i++){
		if(a[i]>a[i-1]) v.push_back(a[i]);
		else check=true;
	}
	sol++;
	//for(auto i : v) cout << i << " ";
	//cout << "\n";
	if(check==true) return xu_li(v);
	return sol;
}
int main(){
//	freopen("treeline.inp","r",stdin);
//	freopen("treeline.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<100;++i++) cout << i << " ";
	return 0;
}
