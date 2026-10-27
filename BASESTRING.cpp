#include <bits/stdc++.h>
using namespace std;
string a,b; 
bool check(int k){
	vector <string> vs,vs2;
	for(int i=0;i<a.length();i+=k){
		string ss;
		for(int j=i;j<i+k;j++) ss+=a[j];
		vs.push_back(ss);
	}
	for(int i=0;i<b.length();i+=k){
		string ss;
		for(int j=i;j<i+k;j++) ss+=b[j];
		vs2.push_back(ss);
	}
//	for(auto i : vs) cout << i << " ";
	for(int i=1;i<vs.size();i++){
		if(vs[i]!=vs[i-1]) return false;
	}
	for(int i=1;i<vs2.size();i++){
		if(vs2[i]!=vs2[i-1]) return false;
	}
	if(vs[0]!=vs2[0]) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	int n=a.length(),m=b.length();
	int i=__gcd(n,m);
	//for(int i=__gcd(n,m);i>=1;i--){
		if(check(i)) {
			string ss;
			for(int ii=0;ii<i;ii++) ss+=a[ii];
			cout << ss ;
			return 0;
		}
	//}
	cout << "NO";
	return 0;	
}

