#include <bits/stdc++.h>
using namespace std;
bool snt[1000005];
int a[305][305];
void tien_xu_li(){
	snt[0]=1;
	snt[1]=1;
	for(int i=2;i*i<=1000000;++i){
		if(snt[i]) continue;
		for(int j=i;j*i<=1000000;j++) snt[j*i]=1;
	}
}
long long sol=0;
int main(){
	tien_xu_li();
	int n,m; cin >>n >> m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
//	for(int i=2;i<=1000;i++) if(!snt[i]) cout <<i << " ";
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int d1=0,d2=0;
			for(int k=1;k<=m;k++){
				if(!snt[a[i][k]]&&!snt[a[j][k]]) d1++;
				else if(!snt[a[i][k]]||!snt[a[j][k]]) d2++;
			}
			sol+=d1*d2+d1*(d1-1)/2;
		}
		
	}
	cout << sol;
	return 0;
}
