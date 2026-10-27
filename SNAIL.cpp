#include <bits/stdc++.h>
using namespace std;
int main(){
long long a,b,h;cin >> a >> b >> h;
	if (a>= h) {
        cout << 1 ; return 0;
    }
	if(b==a){
		cout << -1 ; return 0;
	}
	
	long long sol=(h-a+(a-b)-1)/(a-b);
	cout << sol+1;
	return 0;
}

