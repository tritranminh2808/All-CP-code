#include <bits/stdc++.h>
using namespace std;
bool cmp(pair < pair < int , int > , int > a, pair < pair < int , int > , int > b){
	return a.first.first<b.first.first;
}
bool cmp2(pair < pair < int , int > , int > a, pair < pair < int , int > , int > b){
	return a.first.second>b.first.second;
}

int main(){
	long long n; cin >> n;
	vector < pair < int , int > > v(n);
	vector < pair < pair < int , int > , int > > s;
	vector < pair < pair < int , int > , int > > A,B;
	for(int i=0;i<n;i++) cin >> v[i].first;
	for(int i=0;i<n;i++) cin >> v[i].second;
	for(int i=0;i<n;i++){
		if(v[i].first<v[i].second) A.push_back({v[i],i+1});
		else B.push_back({v[i],i+1});
	}
	sort (A.begin(),A.end(),cmp);
	sort (B.begin(),B.end(),cmp2);
/*	for(int i=0;i<A.size();i++) cout << A[i].first.first << " "<<A[i].first.second << " " << A[i].second << "\n";
	cout << "\n";
	for(int i=0;i<B.size();i++) cout << B[i].first.first << " "<<B[i].first.second << " "<< B[i].second << "\n";
	cout << "\n";*/
	for(int i=0;i<A.size();i++) s.push_back(A[i]);
	for(int i=0;i<B.size();i++) s.push_back(B[i]);


	long long uptime=0,downtime=0;

    vector<int> order; 

 //   for(int i=0;i<n;i++) cout << s[i].first.first << " " << s[i].first.second << " " << s[i].second << "\n";
    for (int i=0;i<n;i++) {
        int k=s[i].second;
        uptime+=v[k-1].first;
        downtime=max(downtime,uptime);
        downtime+=v[k-1].second;

    }
	cout << downtime << "\n";
	for(int i=0;i<n;i++) cout << s[i].second << " ";
} 
