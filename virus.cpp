#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>> t;
	while(t--){
		long long s=0;
		int x;  cin >> x;
		while(x){
			s+=x&1;
			x=x>>1;
		}
		cout << s << "\n";
	}
}
