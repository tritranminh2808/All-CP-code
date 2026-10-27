#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n;
long long sol,m;
pair <int,int> a[100005];
void cook(string s){
	if(s.length()==n){
		long long wi=0,vi=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1') {
				vi+=a[i].second;
				wi+=a[i].first;
			}
		}
		if(wi<=m) sol=max(sol,vi);
		return ;
	}
	cook(s+'0');
	cook(s+'1');
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>> m;
	for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
	cook("");
	cout << sol;
	return 0;
}
