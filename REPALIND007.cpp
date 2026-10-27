#include <bits/stdc++.h>
using namespace std;
bool check(string a)
{
	int i=0,n=a.length();
	for(int j=n-1;j>i;j--){
		if(a[i]!=a[j]){
			return false;
			
		}
		i++;
	}
	return true;
}
int main()
{
	freopen("REPALIND007.inp","r",stdin);
	freopen("REPALIND007.out","w",stdout);
	int n; cin >> n; 
	string s;int k;
	for(int i=0;i<n;i++){
		cin >> s;
		cin >> k;
		if(check(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
