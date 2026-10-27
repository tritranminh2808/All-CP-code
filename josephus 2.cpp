#include<bits/stdc++.h>
using namespace std;
bool check[100005];
int n,k;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("josephus.inp","r",stdin);
	freopen("josephus.out","w",stdout);
	cin >> n >> k;
//	cout << n << k ;
	vector <int > sol;
	int c=k;
	vector <int> v; 
	for(int i=1;i<=n;i++){
		v.push_back(i);
	}
	int i=0;
	while(!v.empty()){
		i+=k-1;if(i>=v.size()) i%=v.size();
		sol.push_back(v[i]);
		v.erase(v.begin()+i);
	}
	for(auto i : sol)  cout << i << " ";
	return 0;
}

