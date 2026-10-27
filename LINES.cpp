#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int a[p],b[p];
int idx[p];
long long f[p],e[p];
int main(){
	int n; cin  >> n; 
	for(int i=0;i<n;i++) {
		cin >> a[i];
		idx[a[i]]=i;
	}
	for(int i=0;i<n;i++) cin >> b[i];
	
	long long sol=0;
	for(int i=0;i<n;i++){
		f[i]=lower_bound(e+1,e+sol+1,idx[b[i]])-e;
		if(f[i]>sol) sol++;
		e[f[i]]=idx[b[i]];
	}
	cout << sol;
	return 0; 
}
