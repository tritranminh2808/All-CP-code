#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin >> n;
	if(n<0) n=0-n;
	int i=0;
	for(i=0;i<=100000;i++){
		if((i+1)*i/2>=n&&((i+1)*i/2-n)%2==0){
			cout << i;
			return 0;
		}
	}
//	cout << i+(i+1)*i/2-n;
	return 0;
}
