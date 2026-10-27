#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("ANAGRAM.INP", "r", stdin);
    freopen("ANAGRAM.OUT", "w", stdout);
	string a,b; cin >> a >> b;
	int n=a.length();
	int x=0;
	for(int i=0;i<n;i++){
		int j=i,z=0;
		for(int k=0;k<n;k++){
			if(a[j]==b[k]){
				z++;
				j++;
			}
		}
		x=max(x,z);
	}
	cout << n-x;
}
