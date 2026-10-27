#include <bits/stdc++.h>
using namespace std;
int uoc(int a, int b){
	if(b==0) return a;
	else return uoc(b,a%b);
}
int t;
int main()
{
	freopen("NTCN.INP","r+",stdin);
	freopen("NTCN.OUT","w+",stdout);
	int n;cin >> n; int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(uoc(a[i],a[j])==1) t++;
		}
	}
	cout <<t;
	return 0;
}
