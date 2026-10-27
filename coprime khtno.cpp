#include <bits/stdc++.h>
using namespace std;
const int maxx=15485900;
bool snt[maxx];
long long v[1000005];
void tienxuli(){
	snt[0]=1;
	snt[1]=1;
	for(int i=2;i*i<maxx;i++){
		if(snt[i]) continue;
		for(int j=i;j*i<=maxx;j++) snt[j*i]=1;
	}
	cout << "usdhfdsf";
	int id=1;
	for(int i=2;i<= 15485900;i++) {
		if(!snt[i]) {
			v[id]=v[id-1]+i;
			id++;
		}
	}
}
int main(){
	tienxuli();
	int n; cin >> n;
	cout << v[n];
	return 0;
}
