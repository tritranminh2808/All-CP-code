#include <bits/stdc++.h>
using namespace std;
long long sol=1;
int timkiem(int a[], int n, int x){
    int l = 0, r = n - 1;
    int pos = -1; 
    while(l <= r){
        int m = (r+l) / 2;
        if(a[m] < x){
            pos = m; 
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return pos;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++){
		int k=1;
		/*for(int j=n-1;j>=0;--j){
			if(a[i]>b[j]) {
				k=j+1;
				break;
			}
		}*/
		//cout << k << " ";
		//cout << timkiem(b,n,a[i]) << " ";
		sol*=(timkiem(b,n,a[i])-i+1);
		sol%=1000000007;
	}
	cout << sol;
	return 0;
}
