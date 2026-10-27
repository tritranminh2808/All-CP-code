#include <bits/stdc++.h>
#define int long long
using namespace std;
long long sol=0;
signed main(){
	int a,b; cin >> a >> b;
	if(a==b){
		cout << 1;
		return 0;
	}
	if(a<b) swap(a,b);
	while(b>0){
		sol+=a/b;
		int x=b;
		b=a%b;
		a=x;
	}
	cout << sol;
}
