
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n; cin >> n;
	long long res=n;
	
	vector<int> v; 
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	for(int i=0;i<v.size();i++){
		res-=((n-(n%v[i])-v[i])/v[i]+1);
	}
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			res+=((n-(n%(v[i]*v[j]))-(v[i]*v[j]))/v[i]/v[j]+1);
		}
	}
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			for(int k=j+1;k<v.size();++k){
				res-=((n-(n%(v[i]*v[j]*v[k]))-(v[i]*v[j]*v[k]))/v[i]/v[j]/v[k]+1);
			}
		}
	}
	res+=(n-(n%(2*3*5*7))-2*3*5*7)/2/3/5/7+1;
	cout << res;
	return 0;
}

