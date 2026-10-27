/*#include <bits/stdc++.h>
using namespace std;
long long t;
int main()
{
	freopen("MAKERECT.INP","r",stdin);
	freopen("MAKERECT.OUT","w",stdout);
	int n,k; cin>>n>>k;int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	long long c=0,b=0;
	for(int i=n-1;i>0;i--){
		if(a[i]==a[i-1]) {
			if(c==0) {
				c=a[i];--i;
			}
			else {
				b=a[i];
				cout << (unsigned long long)c*b; 
				return 0;
			}
		}
	}
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int s,c=0,b;
int main()
{
	freopen("MAKERECT.INP", "r+", stdin);
	freopen("MAKERECT.OUT", "w+", stdout);
	int n; cin >> n;int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[i-1]==a[i] ){
			if(c==0) {
				c=a[i];
				i--;
			}
			else {
				b=a[i];break;
			}
		}
	}
	cout << (long long)c*b;
	return 0; 
}
