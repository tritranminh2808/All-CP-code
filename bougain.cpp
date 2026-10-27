#include <bits/stdc++.h>
using namespace std;
vector <char> a;
int dem(int ind){
	int s=0;
	if(a[max((int)0,ind-2)]==a[ind]) s++;
	if(a[max((int)0,ind-1)]==a[ind]) s++;
	if(a[min((int)ind+1,(int)a.size())]==a[ind]) s++;
	if(a[min((int)ind+2,(int)a.size())]==a[ind]) s++;
	if(a[min((int)ind+3,(int)a.size())]==a[ind]) s++;
	if(a[max((int)0,ind-3)]==a[ind]) s++;
	return s;
}
signed main(){
	string s; cin >> s;
	
	a.push_back('Z');a.push_back('Z');
	for(auto i : s) a.push_back(i);
	int sol=s.length();
	for(int i=2;i<a.size();++i){
		if(a[i]==a[i-2]){
			sol--;
			//cout << sol;
			if(dem(i)>dem(i-2))a.erase(a.begin()+i);
			else a.erase(a.begin()+i-2);
			--i;
		}
		if(a[i]==a[i-1]){
			sol--;
			//cout << sol;
			if(dem(i)>dem(i-1))a.erase(a.begin()+i);
			else a.erase(a.begin()+i-1);
			--i;
		}
	//	for(auto i : a) cout << i;
	//	cout << "\n";
	}
	cout << sol;
	return 0;
}
