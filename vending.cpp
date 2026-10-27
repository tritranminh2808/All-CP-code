#include <bits/stdc++.h>
using namespace std;
int a[1005];
int n,x=1;
int main(){
	freopen("vending.inp","r",stdin);
	freopen("vending.out","w",stdout);
	cin >> n;
	unordered_map <int ,int > mp;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(x>=a[i])x+=a[i];
		else {
			cout << x ;return 0;
		}
	}
	cout << x;
	return 0;
}

