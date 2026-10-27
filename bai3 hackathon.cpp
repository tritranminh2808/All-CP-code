#include <bits/stdc++.h>
using namespace std;
long long s=0;
int main(){
	long long a,k; cin >> a>>k;
	vector <bool> v;
	while(k--){
		s=0;
		v.clear();
		while(a!=0){
			v.push_back(a%2);
			a/=2;
		}
		long long  x=v.size()-1;
		for(long long  i=v.size()-1;i>=0;i--){
			
			s+=pow(8,x)*v[i];
			x--;
		}
		a=s;
		
		cout << s << " ";
	}
	
	
}
