#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,v,l,r; cin >> n >> v >> l >> r;
	int a[n+1],pre[n+1];
	a[0]=0;pre[0]=0;
	 for(int i=1;i<=n;++i){
		int k;cin>>k;
		a[i]=k;
		pre[i]=pre[i-1]+k;
	}
	int sol=0;
	for(int i=1;i<=n-l+1;i++){
		int lf=i+l-1,rt=min(i+r-1,n);
		//cout << rt << " " << lf << endl;
		while(lf<=rt&&(rt+lf)/2<=n){
			
			int mid=(rt+lf)/2;
			//cout << mid << " ";
			if(pre[mid]-pre[i-1]<=v) lf=mid+1;
			else rt=mid-1;
		}
		sol+=lf-i-l+1;
	//	cout <<lf << "\n";
	//	cout << i << " " << sol << "\n";
	}
	cout << sol;
	
	return 0;
}
