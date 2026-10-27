#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("present.inp","r",stdin);
	freopen("present.out","w",stdout);
	int n; cin >> n;
	vector <int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	multiset <int> A,B;
	int sol=0;
	for(int i=1;i<=n;i++){
		A.insert(a[i]);
		B.insert(b[i]);
//		vector <int> x,y;
		bool check=0;
		auto i1=A.begin(),i2=B.begin();
		while(i1!=A.end()){
			if(*i1<*i2) {
				check=1;
				break;
			}
			i1++;
			i2++;
		}
		if(check==0) sol=i;
	}
	cout << sol;
}
