#include <bits/stdc++.h>
using namespace std;
const int pp=1e6+5;
int p[pp][6];
int a[pp];
bool LF(int x,int y){
	int t=0;
	for(int k=1;k<=5;k++){
		if(p[x][k]<p[y][k]) t++;
	}
	if(t>=3) return true;
	return false;
}
int main(){
	int n;
	cin >> n;
	for(int k=1;k<=5;k++){
		
		for(int j=1;j<=n;j++){
			int i;
			cin >> i;
			p[i][k]=j;
		}
	}
	
	for(int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,LF);
	for(int i=1;i<=n;i++) cout << a[i] << " ";
	return 0;
}
