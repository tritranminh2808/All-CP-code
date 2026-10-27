#include <bits/stdc++.h>
using namespace std;
const long long p=5e6+5;
bool check[p];
long long cp[p],a[p];
long long l=-999,s=0;
long long n; 
bool chck(long long a){
	int k=sqrt(a);
	if(k*k==a) return true;
	return false;
}
int main()
{
    cin >> n;
    vector <int> v1,v2;
    for(long long i=0;i<n;i++) {
    	cin >> a[i];
    	if(chck(a[i])) s+=a[i];
	}
	cout << s;
	
}
