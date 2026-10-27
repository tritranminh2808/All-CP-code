#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("subpermute.inp", "r", stdin);
    freopen("subpermute.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin >> t;
    while(t--){
    	int n,k; cin >> n>>k;
    	vector <int> a(n),hoanvi(k);
    	for(int i=1;i<=k;i++) hoanvi[i-1]=i;
    	for(int i=0;i<n;i++) cin >> a[i];
    
    	do{
    		bool check=0;
    		int lwb=-1;
    		for(int i=0;i<k;i++){
    			auto it=find(a.begin()+lwb+1,a.end(),hoanvi[i]);
    			if(it!=a.end()) lwb=it-a.begin();
				else {
					check=1;
					break;
				}
			}
			if(check==0){
				for(auto i : hoanvi) cout << i << " ";
				cout << "\n";
				break;
			}
			
		}
		while(next_permutation(hoanvi.begin(),hoanvi.end()));
	}
    return 0;
}

