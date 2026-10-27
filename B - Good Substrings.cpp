#include <bits/stdc++.h>
using namespace std;
bool check[30];
long long pre[100005];
const int c=31,mod=1e9+7,c2=37,mod2=1e9+9;

long long hashval(string a){
	long long hashP=0;
	for(int i=0;i<a.length();++i)  hashP = (hashP * c + a[i] - 'a' + 1)%mod;
	return hashP;
}
long long hashval2(string a){
	long long hashP=0;
	for(int i=0;i<a.length();++i)  hashP = (hashP * c2 + a[i] - 'a' + 1)%mod2;
	return hashP;
}
long long sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, dep; getline(cin,a);
	getline(cin,dep);
	int M; cin >> M;
	for(int i=0;i<dep.length();i++){
		check[i]=dep[i]-'0';
	}
	vector <string> v;
	if(check[a[0]-'a']==0) pre[0]=1;
	for(int i=1;i<a.length();i++){
		if(check[a[i]-'a']==0) pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1];
	}
	unordered_map<long long,bool> mp;
	for(int i=0;i<a.length();i++){
		string s;
		for(int j=i;j<a.length();j++){
			s+=a[j];
			if(i==0){
				if(pre[j]<=M) {
					if(mp[hashval(s)]==0){
					//	cout << s << endl;
						sol++;
					//	cout << i << endl;
						mp[hashval(s)]=1;
					}
				}
				
			}
			else{
				if(pre[j]-pre[i-1]<=M){
					if(mp[hashval(s)]==0){
					//	cout << s << endl;
						sol++;
					//	cout << i << endl;
						mp[hashval(s)]=1;
					}
				}
			}
		}
	}
	
//	for(auto i : v) cout << i << '\n';

	cout << sol;
	return 0;
}
