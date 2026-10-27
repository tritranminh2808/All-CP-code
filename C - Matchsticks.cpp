#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e5+5;
int st[17][p],st2[17][p];
int a[p];
int n;

void build(){
	for(int i=1;i<=n;i++) st[0][i]=a[i];
	for(int j=1;j<=16;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
}
int find(int l, int r){
	int k=__lg(r-l+1);
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
void build2(){
	for(int i=1;i<=n;i++) st2[0][i]=a[i];
	for(int j=1;j<=16;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st2[j][i]=max(st2[j-1][i],st2[j-1][i+(1<<(j-1))]);
		}
	}
}
int find2(int l, int r){
	int k=__lg(r-l+1);
	return max(st2[k][l],st2[k][r-(1<<k)+1]);
}
int sol,t;
signed main(){
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		a[i]*=2;
	}
	build();
	build2();
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		l++;r++;
		int nd=(l==1)?0:find2(1,l-1)+find(l,r);
		
		int ns=(r+1<n)?find2(r+1,n)+find(l,r) : 0;
		int mid=(find2(l,r)-find(l,r))/2;
		//cout<<ns<<" "<< mid <<"\n";
		cout <<fixed << setprecision(1) << (double)(max(nd,max(ns,mid+find(l,r))))/2 << endl;;
	}
	return 0;
}
