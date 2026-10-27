#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int sol=0;
const int p=1e7+5;
bool check[p];
int main(){
	int n; cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	int j=0,k;
	for(int i=0;i<n;i++){
		if(a[i]==b[j]&&i==j) {i++;j++;
		}
		while(j<n&&a[i]<=b[j]) j++;
		if(j==n) {
			k=i;break;
		}
		if(a[i]>b[j]){
			sol++;j++;
		}
		
	}
	cout << sol-n+k;
	return 0;
}
