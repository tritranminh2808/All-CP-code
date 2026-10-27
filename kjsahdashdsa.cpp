#include <bits/stdc++.h>
using namespace std;
int sol=0;

int main(){
	for(int i=10000;i<=99999;++i){
		if(i*10+2==3*(200000+i)) {
			cout << i << endl;return 0;
		}
	}
	cout << sol;
	return 0;
}
