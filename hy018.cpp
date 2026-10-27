#include <bits/stdc++.h>
using namespace std;
const int p=1e3+1;
bool a[p][p];
int sol=0;
int main(){
	freopen("hy018.inp","r",stdin);
	freopen("hy018.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	while (n--){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i=x1;i<x2;i++){
			for(int j=y1;j<y2;j++) a[i+105][j+105]=1;
		}
	}
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++) if(a[i][j]!=0)sol++;
	}
	cout << sol;
}
