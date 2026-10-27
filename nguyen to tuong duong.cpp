#include <bits/stdc++.h>
using namespace std;
int mp[1000005],sech[1000005],kk,x;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	for(int i=2;i<=1000000;i++){
		kk=1,x=i;
		for(int j=2;j<=sqrt(x);j++){
			if(x%j==0) kk*=j;
			while(x%j==0) x/=j;
		}
		kk*=x;
		sech[i]=kk;
	}
	while(t--){
		int sol=0;
		int a,b; cin >> a >> b;
		for(int i=0;i<=b;i++) mp[i]=0;
		for(int k=a;k<=b;k++)sol+=mp[sech[k]]++;
		cout << sol << "\n";
	}
	return 0;
}
