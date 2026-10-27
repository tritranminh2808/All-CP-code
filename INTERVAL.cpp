#include <bits/stdc++.h>
using namespace std;
long long sol=0;
int main(){
	freopen("interval.inp","r",stdin);
	freopen("interval.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n;cin >> n;
	vector <long long> b,w; 
	for(long long i=0;i<2*n;i++){
		long long a; char c;
		cin >> c >> a;
		if(c=='B') b.push_back(a);
		else w.push_back(a);
	}
	sort(b.begin(),b.end());
	sort(w.begin(),w.end());
	long long k=min(b.size(),w.size());
	for(long long i=0;i<k;i++){
		sol+=abs(b[i]-w[i]);
	}
	cout << sol << endl;
	for(long long i=0;i<k;i++){
		cout << b[i] << " " << w[i] << "\n";
	}
	return 0;
}
