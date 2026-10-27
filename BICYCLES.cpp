#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
using namespace std;
const long long  p=1e6+5;
long long b[p],a[p];
long long n,k,s=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> k;  
    vector <long long > v;
    for(long long  i=0;i<n;i++)
	{
		cin >> a[i];v.push_back(a[i]);
	} 
	sort(v.begin(),v.end());
	int j=n-1,i=0;
	while(i<j){
	//	cout <<i << j;
		if(v[i]+v[j]<=k){
		//	cout << v[i] << " " << v[j] << endl;
			s++;
			i++;
			j--;
		
		}
		else {
			j--;s++;
		}
	}
	if(i==j) s++;
	cout << s;
}

