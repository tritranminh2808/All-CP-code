#include <bits/stdc++.h>
using namespace std;
bool cmp (pair <int,int> a, pair <int,int> b){
	return a.first <b.first;
}
const int p=1e6+5;
int main(){
	int n,k;
	cin >> n>>k; 
	vector <int> a(n);
	vector < pair < int , int > > v(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
		v[i].first=a[i];
		v[i].second=i;
	}
	sort (v.begin(),v.end(),cmp);
	int t=0;
	for(int i=0;i<n-1;i++){
		//cout << k <<  " " << v[i].second << "\n";
		if(v[i].second-t<=k){
			for(int j=i+1;j<n;j++) v[j].second++;
			k-=v[i].second;
			a.erase(a.begin()+v[i].second);
			int m=a[t],z;
			a[t]=v[i].first;
			
			for(int i=t+1;i<n;i++){
				z=a[i];
				a[i]=m;
				m=z;
			}
			t++;
		}
		for(int i=0;i<n;i++) cout << a[i] << " ";
		cout << t << "\n";
		
	}
	for(int i=0;i<n;i++) cout << a[i] << " ";
	return 0;
}
