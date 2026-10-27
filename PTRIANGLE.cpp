#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n; cin >> n;vector <long long> v;vector <long long> v2;
	if(n==0){
		cout << 1;return 0;
	}
	v.push_back(1);v2.push_back(1);v2.push_back(1);
	cout << "1\n1 1\n";
	n-=2;
	while (n>=0){
		
		v.clear();
		v.push_back(1);
		for(long long i=0;i<v2.size()-1;i++){
			v.push_back(v2[i]+v2[i+1]);
		}
		v.push_back(1);
		for(long long i=0;i<v.size();i++) cout << v[i] << " ";
		cout << "\n";
		v2.clear();
		for(long long i=0;i<v.size();i++) v2.push_back(v[i]);
		n--;
	}
	return 0;
}
