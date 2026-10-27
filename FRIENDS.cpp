#include <bits/stdc++.h>
using namespace std;
bool scp(long long a){
	long long b=sqrt(a);
	if(b*b==a) return true;
	return false;
}

long long tong_uoc(long long a){
	long long t=1;
	for(int i=2;i*i<a;i++){
		if(a%i==0) {
			t+=i;t+=a/i;
		}
	}
	if(scp(a)) t+=sqrt(a);
	return t;
}
int main(){
	int t; cin >> t;
	for(int z=0;z<t;z++){
		long long a,b; cin>> a >> b;
		if(tong_uoc(a)==b&&tong_uoc(b)==a){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
