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
    max1=a[n-1];
    min1=a[0];
    int i=1,j=n-2;
    while(a[i]==min1){
    	i++;
	}
	min2=a[i];
	while(a[j]==max1){
    	j--;
	}
	max2=a[j];
	cout << max1 << " " << max2 << endl << min1 << " " << min2;
}
