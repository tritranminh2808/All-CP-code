#include <bits/stdc++.h>
using namespace std;
int s;
bool scp(int a){
	int k=sqrt(a);
	if(k*k==a) return true;
	return false;
}
int uoc(int n){
	int t=0;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0) t++; 
	}
	return t*2-1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("TPRIME.INP","r+",stdin);
	freopen("TPRIME.OUT","w+",stdout);
	int n;cin>>n;
	for(int i=n;i>=4;i--){
		if(scp(i)){
			if(uoc(i)==3) s++;
		}
	}
	cout<< s;
	return 0;
}
