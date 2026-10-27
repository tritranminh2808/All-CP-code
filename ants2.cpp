#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a, int b){
	if(abs(a)==abs(b)) return a<b;
	return abs(a)<abs(b);
}
int sol=0;
signed main(){
	int n; cin >> n;
	vector <int> a;
	for(int i=0;i<n;i++){
		int x; cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end(),cmp);
	int vt=a[n-1];
	vector< pair< int, int > > v;
	for(int i=0;i<n;i++){
		if(abs(a[i])==abs(a[i+1])) {
			v.push_back({a[i],a[i+1]});
			i++;
		}
		else v.push_back({a[i],a[i]});	
	}
	reverse(v.begin(),v.end());
	for(auto i : v) {
		if(abs(vt-i.first)<abs(vt-i.second)){
			sol+=abs(vt-i.first);
			vt=i.second;
		}
		else {
			sol+=abs(vt-i.second);
			vt=i.first;
		}
		sol+=abs(i.first-i.second);
//		cout << sol << "\n";
	}
	if(abs(a[n-1])==abs(a[n-2])){
		int vt2=a[n-2];
		int sol2=0;
		for(auto i : v) {
			if(abs(vt2-i.first)<abs(vt2-i.second)){
				sol2+=abs(vt2-i.first);
				vt2=i.second;
			}
			else {
				sol2+=abs(vt2-i.second);
				vt2=i.first;
			}
			sol2+=abs(i.first-i.second);
	//		cout << sol << "\n";
		}
		cout << min(sol2+abs(vt2),sol+abs(vt)) ;
		return 0;
	}
	cout << sol+abs(vt);
	return 0;
}
