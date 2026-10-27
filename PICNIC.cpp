#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int a[p],n;
bool cmp(int a,int b){
	if(abs(a)==abs(b)) return a>b;
	return abs(a)<abs(b);
}
long long sol=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	int pos=0;
	for(int i=0;i<n;i++){
		sol+=abs(a[i]-pos);
		pos=a[i];
	}
	cout << sol;
	return 0;
}
