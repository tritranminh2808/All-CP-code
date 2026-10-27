#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
bool check[p];
int main() {
    int n; cin >> n;
    long long a[n];
    vector <int> v;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
    	cin >> a[i];
    	if(check[a[i]]==0){
    		v.push_back(a[i]);
    		check[a[i]]=1;
		}
	}
	for(auto i : v) cout << i << " ";
    return 0;
}

