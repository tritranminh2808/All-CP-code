#include <bits/stdc++.h>
using namespace std;
const long long p=5e6+5;
bool check[p];
long long cp[p],a[p];
long long l=-999,s=0;
long long n; 
int main()
{
    cin >> n;
    vector <int> v1,v2;
    for(long long i=0;i<n;i++) {
    	cin >> a[i];
    	if(a[i]%2==0) v1.push_back(a[i]);
    	else v2.push_back(a[i]);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(auto i:v1) cout << i << " ";
	for(int i=v2.size()-1;i>=0;i--) cout << v2[i] << " "; 
//	cout << s << " " << l;
}
