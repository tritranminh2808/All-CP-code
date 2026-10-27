#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a; cin >> a;
		int sol=1;
		for(int i=0;i<2*n-1;i++) if(a[i]=='('&&a[i+1]=='(') sol++;
		cout << sol<<"\n";
	}
	return 0;
}
