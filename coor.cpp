#include <bits/stdc++.h>
using namespace std;
int main(){
	int x=0,y=0;
	string s; cin >> s;
	for(auto i : s){
		if(i=='E') x++;
		else if(i=='S') y--;
		else if(i=='W')x--;
		else y++;
	}
	cout << x << " " << y;
	return 0;
}
