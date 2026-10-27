#include <bits/stdc++.h>
using namespace std;
int pre[1000006];
int main(){
	for(int i=2;i<=sqrt(1000006);++i){
		int k=i*i;
		for(int j=0;j+k<1000006;j+=k) pre[j+k]=1;
	}
	for(int i=1;i<1000006;i++) pre[i]+=pre[i-1];
	int t; cin >> t;
	while(t--){
		int l,r; cin >> l >> r;
		cout << r-l+1-pre[r]+pre[l-1] << "\n";
	}
	return 0;
}
