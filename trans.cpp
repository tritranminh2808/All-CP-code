#include <bits/stdc++.h>
#define int long long
int dp[100005];
using namespace std;
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
int sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	int a,b,d; cin>> a >> b>>d;
	int x=lcm(a,b);
	int y=x/a;
	vector<int> v;
	for(int i=2;i<=sqrtl(y);i++){
		while(y%i==0){
			v.push_back(i);
			y/=i;
		}
	}
	if(y!=1)v.push_back(y);
//	cout << v.size(); 
//for(auto i : v) cout << i ;
	int cur=1,cnt1=1;
	for(auto i : v){
		if(cur*i<=d) cur*=i;
		else{
			cnt1++;
			cur=i;
		}
	}
//	soL+=
//	if(cnt1!=0) cnt1++;
	sol+=cnt1;
	int z=x/b;
	vector<int> v2;
	for(int i=2;i<=sqrtl(z);i++){
		while(z%i==0){
			v2.push_back(z);
			z/=i;
		}
	}
	if(z!=1)v2.push_back(z);
	cur=1;cnt1=1;
	for(auto i : v2){
		if(cur*i<=d) cur*=i;
		else{
			cnt1++;
			cur=i;
		}
	}
//	if(cnt1!=0) cnt1++;
	sol+=cnt1;
	cout << sol;
	return 0;
}
