#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
long long sol=0;
long long cok(int k){
	long long c1=0,c2=0;
	int cnt1=n,cnt2=n,id1=k,id2=k;
	while(cnt1--){
		c1*=10;
		c1+=a[id1];
		id1++;
		if(id1>n) id1%=n;
	}
	while(cnt2--){
		c2*=10;
		c2+=a[id2];
		id2--;
		if(id2==0) id2=n;
	}
	return max(c1,c2);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
//	for(int i=n+1;i<=2*n-1;++i) a[i]=a[i-n];
//	for(int i=1;i<=2*n-1;i++) cout << a[i] << " ";
	for(int i=1;i<=n;i++) sol=max(sol,cok(i));
	cout << sol;
	return 0;
	
}
