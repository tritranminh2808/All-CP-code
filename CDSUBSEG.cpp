#include <bits/stdc++.h>
using namespace std;
const int  p=1e6+5;
int n; 
vector<int> a(p);
bool check(int  k){
	vector <int > l(n,0);
	vector <int > r(n,0);
	for(int  i=0;i<n;i++){
		if(i%k==0)	l[i]=a[i];
		else l[i]=__gcd(l[i-1],a[i]);
	}
	for(int  i=n-1;i>=0;i--){
		if(i==n-1||(i+1)%k==0)	r[i]=a[i];
		else r[i]=__gcd(r[i+1],a[i]);
	}
	for(int  i=0;i<n-k+1;i++){
		if(__gcd(r[i],l[i+k-1])!=1) return true;
	}
	return false;
}
int  xuli (){
	int l=1,r=n;
	while(l<=r){
		int  mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else r=mid-1;
	}
	return l-1;
}
int  main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	
	while(t--){

		a.clear();
		cin>>n;
		
		for(int i=0;i<n;i++) {
			cin>>a[i];a[i]=abs(a[i]);
		}
		cout << xuli() << "\n";
	}	
    return 0;
}
