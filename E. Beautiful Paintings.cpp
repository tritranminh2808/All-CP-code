#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector <int> nn;
	for(int i=1;i<=n;i++){
		int k; cin >> k;
		nn.push_back(k);
	}
	sort(nn.begin(),nn.end());
	
	vector <pair <int, int > > v;
	v.push_back({nn[0],1});
	for(int i=1;i<nn.size();i++){
		if(nn[i]==v[v.size()-1].first) v[v.size()-1].second++;
		else v.push_back({nn[i],1});
	}
	return 0;
}
