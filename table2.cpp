#include <bits/stdc++.h>
using namespace std;
int a[1005][1005],pre[1005][1005];
int n, m;
bool check(int ind){
	for(int i=1;i<=n-ind+1;i++){
		for(int j=1;j<=m-ind+1;j++){
			if(a[i][j]==1) if(pre[i+ind-1][j+ind-1]-pre[i+ind-1][j-1]-pre[i-1][j+ind-1]+pre[i-1][j-1]==ind*ind){
			//	cout << ind << " " << i << " " << j << " " << pre[i+ind-1][j+ind-1]-pre[i+ind-1][j-1]-pre[i-1][j+ind-1]+pre[i-1][j-1] << "\n";
				 return true;
				 
			}
		}
	}
	return false;
}
void check2(int ind){
	for(int i=1;i<=n-ind+1;i++){
		for(int j=1;j<=m-ind+1;j++){
			cout << ind << " " << i << " " << j << " " << pre[i+ind-1][j+ind-1]-pre[i+ind-1][j-1]-pre[i-1][j+ind-1]+pre[i-1][j-1] << "\n";	
		}
}
}
int sol=-9999;
int main(){
	 cin >> n>> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
	}
	int l=1,r=min(n,m);
//	check2(2);
	while(l<=r){
		int mid=(r+l)/2;
	//	cout << mid << "\n";
		if(check(mid)){
			sol=(sol,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << sol;
}
