#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	int n,m; cin >> n >> m;
	while(m--){
		int r,x; cin >> x >> r;
		for(int i=0;i<=r;i++){
			a[x+i]=1;
			a[max(0,x-i)]=1;
		}
	}
	int sol=0;
	for(int i=1;i<=n;i++) if(a[i]==1) sol++;
	cout << sol;
	return 0;
}
