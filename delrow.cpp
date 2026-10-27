#include <bits/stdc++.h>
using namespace std;
bool so_sanh(string a, string b){
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i]) return false; 
	}
	return true;
}
bool check(vector <string> v){
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();++j){
			if(so_sanh(v[i],v[j])) return false;
		}
	}
	return true;
}

int main(){
	freopen("delrow.inp","r",stdin);
	freopen("delrow.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,l; cin >> n >> l;
	vector <string> ss;
	for(int i=0;i<n;i++){
		string s; cin >> s;
		ss.push_back(s);
	}
	vector <string> v;
	for(int i=0;i<l;i++){
		string s;
		for(auto j : ss){
			s+=j[i];
		}
		v.push_back(s);
	}
	int sol=0;
	//for(auto i :v) cout << i << "\n";
	
	while(check(v)){
	//	for(auto i :v) cout << i << " ";
	//	cout << "\n";
		sol++;
		for(int i=0;i<v.size();++i){
			v[i].erase(0,1);
		}
	//	for(auto i :v) cout << i << " ";
	}
	cout << sol-1;
	return 0;
}
