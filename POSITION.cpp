#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int > Mul(const vector <int>& a,const  vector<int>& b){
	vector <int> c(n);
	for(int i=0;i<n;++i)c[i]=b[a[i]];
	return c;
}
vector <int> f,g;
vector <int> Power(const vector <int>& a,int m){
	vector <int> c(n),t=a;
	iota(c.begin(),c.end(),0);
	for(;m>0;m/=2){
		if(m%2==1)c=Mul(c,t);
		t=Mul(t,t);
	}
	return c;
}
int main() {
    
    cin >> n >> m;
    f.resize(n);
    

    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    g=Power(f,m);
    for(auto i:g) cout << i << " ";
    return 0;
}

