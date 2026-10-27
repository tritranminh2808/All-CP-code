#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],l[1000005],r[1000005];
bool cmp(int a, int b){
	return a>b;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>> t;
	while(t--){
		int n,m,k; cin >> n>>m>>k;
		int row=k/n,du=k%n;
//		cout << row << du << endl;
		if(du>0) row++;
		int x=0;
//		if()
		 x=row/(m-row+1);
		 if(row%(m-row+1)!=0) x++;
		cout << x << "\n";
	}
	return 0;
}
