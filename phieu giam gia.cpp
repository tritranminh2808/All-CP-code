#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check[1000005];
int cal(int x){
	int f1=x/1000,f2=(x/100)%10,f3=(x/10)%10,f4=x%10;
	int l=f1+f2,r=f3+f4;
	swap(l,r);
	return l*100+r;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a; cin >> a;
	for(int i=1000;i<=9999;i++) {
		if(cal(i)==a){
			cout << i;
			return 0;
		}
	}
	cout << 0;
//	for(int )
}
