#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n,k; cin >> n >> k;
		vector <int> a(n+1);
		bool check=0;
		if(k==0) for(int i=1;i<=n;i++) cout <<i <<  " ";
		else if(n%(2*k)!=0) cout << -1;
		else{
			for(int i=0;i<n/(2*k);i++){
                for(int j=1;j<=2*k;j++){
                    int pos=i*2*k+j;
                    if(j<=k) a[pos]=pos+k;
                    else a[pos]=pos-k;
                }
            }
			for(int i=1;i<=n;i++) cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
