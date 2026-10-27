#include <bits/stdc++.h>
using namespace std;
int n; 
void cook(string s){
	if(s.length()==n){
		cout << s << "\n";
		return ;
	}
	cook(s+'0');
	cook(s+'1');
	cook(s+'2');
}
int main(){
	cin >> n;
	cook("");
	return 0;
}
