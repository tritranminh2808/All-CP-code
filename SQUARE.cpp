#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
bool chck(int i,int i2, int j, int j2){
	int s=a[i][j];
	for(int k=i;k<=i2;k++){
		for(int p=j;p<=j2;p++){
			if(a[k][p]!=s) return false;
		}
	}
	return true;
}
int d=-999;
int main()
{
	freopen("SQUARE.inp", "r", stdin);
//	freopen("SQUARE.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin >> a[i][j];
	}
	int b[4];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			for(int k=1;k<=n;k++){
				int i2=i+k,j2=j+k;
				if(i2>=n||j2>=m) break;
				if(chck(i,i2,j,j2)){
					if(k+1>d)d=k+1;
				}
			}
		}
	}
	/*for(int i=2;i<9;i++){
		for(int j=2;j<9;j++) cout << a[i][j] << " " ;
		cout << "\n";
	}*/
	cout << d*d /*<< "\n" << b[0]+1 << " " << b[1]+1 << " " << b[2]+1 << " " << b[3]+1*/;
	return 0;
	
}
