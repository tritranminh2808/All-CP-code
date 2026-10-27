#include <bits/stdc++.h>
using namespace std;
const long long p=1e6+5;
long long a[p],b[p];long long nn,m,n;
bool check=0;
int main(){
	cin >> nn;
	set <int> st;
	for(long long i=0;i<nn;i++){
		cin >> a[i];
		st.insert(a[i]);
		b[i]=a[i];
	}
	if(st.size()>2){
		cout << 0 ; return 0;
	}
	sort(b,b+nn);
	int k;
	if(b[0]!=b[1]){
		k=b[0];
	}
	else if(b[nn-2]!=b[nn-1]){
		k=b[nn-1];
	}
	else{ cout << 1 ; return 0;}
	for(int i=0;i<nn;i++){
		if(a[i]==k) {
			cout << i+1; return 0;
		}
	}
	return 0;
}
