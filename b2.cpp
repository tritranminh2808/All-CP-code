#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int pt(int a){
	vector <int> v;
	for(int i=2;i<=sqrt(a);i++){
		while(a%i==0){
			a/=i;v.push_back(i);
		}
	}
	if(a!=1) v.push_back(a);
	return v.size();
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin >> t;
	for(int qq=0;qq<t;qq++){
		int a,b;
		cin >> a >> b;
		int sol=0;
		sol+=pt(a/gcd(a,b))+pt(b/gcd(a,b));
		cout << sol <<"\n";
	}
	return 0;
}
