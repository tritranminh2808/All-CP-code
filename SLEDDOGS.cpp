#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
const long long p=1e7+5;
bool checka[p];
bool checkb[p];
long long sol=0;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n,k; cin >> n >> k;
	long long a[n],b[n];
	for(long long i=0;i<n;i++) {
		cin >> a[i];
		int p=(a[i]+k-1)/k;
		sol+=p;a[i]=p*k-a[i];
	}
	for(long long i=0;i<n;i++) {
		cin >> b[i];
		int p=(b[i]+k-1)/k;
		sol+=p;b[i]=p*k-b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	int j=n-1;
	for(int i=0;i<n;i++){
		if(a[i]+b[j]>=k){
			sol--;j--;
		}
	}
	cout << sol;
	return 0;
}
