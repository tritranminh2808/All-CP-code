#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("MINNUM.INP" ,"r", stdin);
	freopen("MINNUM.OUT" ,"w", stdout);
	int n,s;
	cin>>n>> s;
	
	vector<int> vitri;
	int j =9;
	int k = (s-1)/j;
	int mod = (s-1) % 9;
	int chuso = n - 2 -k;
	if(s == 9*n){
		for(int i =0 ; i<n;i++) cout<< 9 ;
		return 0;
	}
	if(k == n-1){
		cout<< s % 9;
		for(int i = 1; i<=n-1; i++) cout<< 9;
		
	}else{
		cout<< 1;
		if(chuso!= 0){
			for(int i  =1 ; i<= chuso ;i++) cout<< 0;
			
		}
		cout<< mod;
		for(int i  =1;i<= k ;i++) cout<< 9;
	}
}
