#include <bits/stdc++.h>
using namespace std;
int speed1[100005],speed2[100005];
int main(){
	int x,n, m;
	cin >>x>> n >> m;
	vector <pair <int, int >> s(n), a(n);
	for(int i=0;i<n;i++){
		cin >> s[i].second >> speed1[i];
		if(i>0) {
			s[i].second+=s[i-1].second;
			s[i].first=s[i-1].second +1;
		}
		else s[i].first =0;
	}
	for(int i=0;i<m;i++){
		cin >> a[i].second >> speed2[i];
		if(i>0) {
			a[i].second+=a[i-1].second;
			a[i].first=a[i-1].second +1;
		}
		else a[i].first =0;
	}
	for(auto i : a) cout  << i.first << " " << i.second <<"\n";
	vector <int > sol(n);
	int ind=0;
	for(auto i=0;i<m;i++){
		while(ind<n){
			if(speed2[i]>speed1[ind]) sol[i]=
		}
	}
	return 0;
}
