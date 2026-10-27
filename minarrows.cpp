#include <bits/stdc++.h>
using namespace std;
vector <int> v(1000006,0);
int a[1000006];
int n,x=1;
int main(){
	freopen("minarrows.inp","r",stdin);
	freopen("minarrows.out","w",stdout);
	cin >> n;
	int sol=0,dcaomax=-1;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		if(v[a[i]]>0){
			v[a[i]]--;v[a[i]-1]++;
		}
		else if(v[a[i]]==0){
			v[a[i]-1]++;sol++;
		}
	}
	cout << sol;
	return 0;
}

