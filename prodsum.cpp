#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e6+5;
int r1,r2;
vector <int> a1,a2;
signed main(){
	int n; cin>> n;
	int maxn=-INT_MAX,minn=INT_MAX,csma,csmi;
	for(int i=0;i<n;i++){
		int k;cin >> k;
		a1.push_back(k);
		a2.push_back(k);
		if(a1[i]>maxn){
			maxn=a1[i];
			csma=i;
		}
		if(a1[i]<minn){
			minn=a1[i];
			csmi=i;
		}
	}
	a1.erase(a1.begin()+csma); 
	a1.push_back(maxn);
	
	a2.erase(a2.begin()+csmi); 
	a2.insert(a2.begin(),minn);
	for(int i=0;i<n;i++) {
		r1+=(i+1)*a1[i];
		r2+=(i+1)*a2[i];
	}
	cout << max(r1,r2);
    return 0; 
}
