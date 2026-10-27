#include <bits/stdc++.h>
using namespace std;

const int p=1e5+5;
int a[p];
bool check[p];

bool cmp(pair <int , int > a, pair< int, int > b){
	if(a.second==b.second) return a.first < b.first;
	return a.second < b.second;
}
int sol;
int main() {
    int n;
    cin >> n;
    vector <pair < int, int > > v;
    for(int i=0;i<n;i++){
    	int l,r; cin >> l >> r;
    	v.push_back({l,r});
	}
	int i=0;
	sort(v.begin(),v.end(),cmp);
	stack <pair <int, int > > st;
	for(int i=0;i<n;i++){
		if(!st.empty()){
			if(st.top().first>=v[i].first) continue;
			if(st.top().first>v[i].first&&st.top().second<v[i].second) continue;
			else st.push(v[i]);
		}
		else st.push(v[i]);
	}
	cout << st.size();
    return 0;
}

