#include <bits/stdc++.h>
using namespace std;
set <int> sech;
bool vst[1000005];
void cook(int n){
	vst[n]=1;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0&&!vst[(i-1)*(n/i+1)]){
			sech.insert((i-1)*(n/i+1));
			cook((i-1)*(n/i+1));
		}
	}
	return;
}
int main(){
	int n; cin >> n;
	cook(n);
	vector <int> sol;
	for(auto i : sech) sol.push_back(i);
	cout << sol.size() << "\n";
	int ind=0;
	while(ind<sol.size()){
		cout << sol[ind];
		ind++;
		if(ind%10==0) cout << "\n";
		else cout << " ";
	}
	return 0;
}
