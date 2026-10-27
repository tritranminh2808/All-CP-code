#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[105][105];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; 
	cin >> n;
	if(n==2){
		cout << -1; return 0;
	}
	if(n%2){
		int id=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout << id << " ";
				id++;
			}
			cout << "\n";
		}
		return 0;
	}
	long long id=0;
	for(int i=1;i<n;i++){
		int sum=0;
		for(int j=1;j<n;j++){
			id++;
			sum+=id;
			a[i][j]=id;
		}
		sum-=id;
		int it=id*(n-1)-sum;
		a[i][n]=it;
		id=it;
	}
	for(int j=1;j<=n;j++){
		int sum=0;
		for(int i=1;i<n;i++) sum+=a[i][j];
		int it=a[n-1][j]*n-sum;
		a[n][j]=it;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout << a[i][j] << " ";
		cout <<"\n";
	}
	return 0;
}
