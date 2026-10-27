#include <bits/stdc++.h>
using namespace std;
bool cmp(pair < int , pair < int, int > > a, pair < int , pair < int, int > > b){
	return a.second.second > b.second.second;
}
bool cmp2(pair < int , pair < int, int > > a, pair < int , pair < int, int > > b){
	return a.first < b.first;
}
const int p=1e5+5;
int a[p];
long long sol=0;
int main(){
	freopen("BALO.inp","r",stdin);
	freopen("BALO.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,  m;
	cin >> n >> m;
	vector < pair < int , pair < int , int > >> v;
	for(int i=0;i<n;i++){
		int b;
		cin>> a[i] >> b;
		v.push_back({i+1,{a[i],b}});
	}
	sort(v.begin(),v.end(),cmp);
	int iii=0;
	for(auto i:v){
	//	cout << i.first << " " << i.second.first << " " <<i.second.second << " " << sol<< "\n";
		if(m==0) break;
		int k=min(i.second.first,m);
		sol+=i.second.second*k;
		m-=k;
		v[iii].second.first-=k;
		iii++;
	}
	sort(v.begin(),v.end(),cmp2);
	int ii=0;
	
	for(auto i:v){
		//cout << i.first << " " << i.second.first << " " <<i.second.second << " " << sol<< "\n";
		cout << a[ii]-i.second.first << "\n";
		++ii;
	}
	cout << sol;
}
