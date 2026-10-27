#include <bits/stdc++.h>
using namespace std;
int n,k;
int v[20];
bool sinh(){
	int i=k-1;
	while(i>=0&&v[i]==n-k+1) --i;
	if(i>=0) iota(v+i,v+k,v[i]+1);
	return i>=0;
}
int main() {
    //freopen("subsets.inp","r",stdin);
    //freopen("subsets.out","w",stdout);
    
    cin>>n>>k;
    iota(v,v+k,0);
    do{
    	for(int i=0;i<k;i++) cout << v[i] << " ";
		cout << "\n";
	}
	while(sinh());

    return 0;
}

