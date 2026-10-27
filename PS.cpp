#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 5;
const long long INF = 1e6 + 5;
long long n, a[MAXN],s[MAXN], check[MAXN];
long long sol=0;
bool cmp(pair < long long , long long > a, pair < long long , long long > b) {
	return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; i++) {
    	cin >> a[i];
    	s[i]=s[i-1]+a[i];
	}
	long long x=1,y=n,maxx=-1;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[j]-s[i-1]>0){
				if(maxx<j-i+1){
					maxx=j-i+1;
					y=j;x=i;
				}
			}
		}
	}
//	cout << s[9]-s[3-1];
	cout << x << " " << y  ;
}
