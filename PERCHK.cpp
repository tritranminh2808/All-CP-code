#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
long long a[N];
long long max1=-1e9-1,max2=-1e9-1,min1=1e9+1,min2=1e9+1;
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort (a,a+n);
    for(int i=0;i<n;i++){
    	if(a[i]!=i+1) {
    		cout << "NO";return 0;
		}
	}
	cout << "YES"; 
}
