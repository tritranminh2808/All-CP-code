#include <bits/stdc++.h>
using namespace std;
string a[100005];
int main(){
	freopen("DEMSO.INP","r",stdin);
	freopen("DEMSO.OUT","w",stdout);
	int n; cin >> n;
	int sa=0,sd=0;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(a[i][0]=='-') sa++;
		else if(a[i][0]=='0') continue;
		else sd++;
	}
	cout<<sa<<" "<<sd;
}
